#include<iostream>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

bool F[3010][3010];
ll pfx[3010][3010];

int f(int i, int j, int n){
  return pfx[i+n-1][j+n-1] - pfx[i+n-1][j-1] - pfx[i-1][j+n-1] + pfx[i-1][j-1];
}

int main(){
  int H, W, N; cin >> H >> W >> N;
  rep(i, 0, N){
    int a, b; cin >> a >> b;
    F[a][b] = true;
  }
  
  // 2d prefix sum
  rep(i, 1, H+1)rep(j, 1, W+1) pfx[i][j] = pfx[i][j-1] + F[i][j];
  rep(j, 1, W+1)rep(i, 1, H+1) pfx[i][j] += pfx[i-1][j];

  ll answer = 0;
  rep(i, 1, H+1)rep(j, 1, W+1)if(!F[i][j]){
    // binary search
    int l = 1, r = min(H-i, W-j) + 2;
    while(l+1 < r){
      int m = (l + r) / 2;
      if(f(i, j, m) == 0) l = m;
      else r = m;
    }  
    answer += l;
  }
  
  cout << answer << endl;
  return 0;
}