#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using P = pair<int, int>;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int F[25][25], N, H, W;
P recs[10];
bool found;

void dfs(vector<int> &v, int n){
  if(n == (int)v.size()){
    found = true;
    return ;
  }

  rep(k, 0, 2){
    int h, w;
    if(k == 0) h = recs[v[n]].first, w = recs[v[n]].second;
    else       w = recs[v[n]].first, h = recs[v[n]].second;
    rep(i, 0, H)rep(j, 0, W)if(F[i][j] == 0){
      bool f = true;
      rep(di, 0, h)rep(dj, 0, w){
        f = f && i+di < H && j+dj < W && F[i+di][j+dj] == 0;
        F[i+di][j+dj] += 1;
      }
      if(f) dfs(v, n+1);
      rep(di, 0, h)rep(dj, 0, w) F[i+di][j+dj] -= 1;
      // if(f) break;
    }
    if(h == w) break;
  }
}

bool precheck(vector<int> &v){
  int area = 0;
  for(auto i : v){
    area += recs[i].first * recs[i].second;
  }
  return area == H*W;
}

void solve(int n){
  vector<int> v;
  
  rep(i, 0, N){
    int m = n & (1 << i);
    if(m > 0) v.push_back(i);
  }
  if(!precheck(v)) return ;
  dfs(v, 0);
}


int main(){
  cin >> N >> H >> W;
  rep(i, 0, N){
    int a, b; cin >> a >> b;
    if(a < b) swap(a, b);
    recs[i] = {a, b};
  }sort(recs, recs+N, greater<P>());

  rep(i, 1, 1<<N){
    if(found) break;
    solve(i);
  }

  cout << (found ? "Yes" : "No") << endl;
}