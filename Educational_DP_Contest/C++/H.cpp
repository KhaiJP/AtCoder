#include<iostream>
#include<atcoder/all>
using namespace std;
using mint = atcoder::modint1000000007;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int H, W;
bool F[1010][1010];
mint dp[1010][1010];

int main(){
  cin >> H >> W;
  rep(r, 1, H+1)rep(c, 1, W+1){
    char a; cin >> a;
    F[r][c] = a == '.';
  }

  dp[1][1] = 1;
  rep(r, 1, H+1)rep(c, 1, W+1){
    if(F[r][c+1]) dp[r][c+1] += dp[r][c];
    if(F[r+1][c]) dp[r+1][c] += dp[r][c];
  }

  cout << dp[H][W].val() << endl;
  return 0;
}