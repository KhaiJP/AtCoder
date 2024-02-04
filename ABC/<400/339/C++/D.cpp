#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int DR[] = {-1,  0,  1,  0, -1,  1,  1, -1};
int DC[] = { 0,  1,  0, -1,  1,  1, -1, -1};
bool F[100][100];
int N, t, dist[70][70][70][70], inf = 1e9;
vector<int> v0(5);
queue<vector<int>> q;

int get_dist(vector<int> &v){
  return dist[v[0]][v[1]][v[2]][v[3]];
}

bool set_dist(vector<int> &v, bool force){
  if(get_dist(v) <= v[4] && !force) return false;
  dist[v[0]][v[1]][v[2]][v[3]] = v[4];
  return true;
}

int main(){
  cin >> N;
  rep(i, 1, N+1)rep(j, 1, N+1){
    char c; cin >> c;
    F[i][j] = c == '.';
    if(c == 'P'){
      v0[2*t] = i, v0[2*t+1] = j;
      F[i][j] = true;
      ++t;
    }
  }
  
  rep(i, 1, N+1)rep(j, 1, N+1)rep(k, 1, N+1)rep(l, 1, N+1){
    vector<int> tmp = {i, j, k, l, inf};
    set_dist(tmp, true);
  }

  q.push(v0);
  set_dist(v0, false);

  while(q.size()){
    auto v = q.front();
    q.pop();
    if(get_dist(v) < v[4]) continue;
    rep(k, 0, 4){
      auto u = v;
      rep(i, 0, 2){
        int tmp_r = v[2*i]   + DR[k];
        int tmp_c = v[2*i+1] + DC[k];
        if(F[tmp_r][tmp_c]){
          u[2*i]   = tmp_r;
          u[2*i+1] = tmp_c;
        }
      }
      ++u[4];
      if(set_dist(u, false)){
        q.push(u);
      }
    }
  }

  int answer = inf;
  rep(i, 1, N+1)rep(j, 1, N+1){
    vector<int> tmp = {i, j, i, j};
    answer = min(answer, get_dist(tmp));
  }

  cout << (answer < inf ? answer : -1) << endl;
  return 0;
}