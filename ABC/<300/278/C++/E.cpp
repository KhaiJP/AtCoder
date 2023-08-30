#include<iostream>
#include<set>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int H, W, N, h, w, A[310][310];
int cnt[310][310][310];

int solve(int r, int c){
  int answer = 0;
  rep(n, 1, N+1){
    int tmp = 0;
    tmp  = cnt[H][W][n];
    tmp -= cnt[r+h-1][c+w-1][n];
    tmp += cnt[r+h-1][c-1][n] + cnt[r-1][c+w-1][n];
    tmp -= cnt[r-1][c-1][n];
    answer += tmp > 0; 
  }
  return answer;
}

int main(){
  cin >> H >> W >> N >> h >> w;
  rep(r, 1, H+1)rep(c, 1, W+1) cin >> A[r][c];
  rep(r, 1, H+1)rep(c, 1, W+1) ++cnt[r][c][A[r][c]];

  // 2 dimensional prefix sum
  rep(n, 1, N+1)rep(r, 1, H+1)rep(c, 1, W+1) cnt[r][c][n] += cnt[r][c-1][n];
  rep(n, 1, N+1)rep(c, 1, W+1)rep(r, 1, H+1) cnt[r][c][n] += cnt[r-1][c][n];

  rep(r, 1, H-h+2){
    rep(c, 1, W-w+2) cout << solve(r, c) << ' ';
    cout << endl;
  }

  return 0;
}