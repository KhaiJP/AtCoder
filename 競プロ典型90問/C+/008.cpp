#include<iostream>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

// Typical dynamic-programming problem.
// if there are M ways to realise "atcode" up to i-1-th character of S
// and the i-th is r -> there are other M ways to realise "atcoder" up to the i-th.

// dp[i][j] : number of realisation of [0, j) of "atcoder"
// [0,0) = "", [0, 1) = "a", [0, 7) = "atcoder"
ll dp[1000010][8];
const ll MOD = 1000000007;

int main(){
  ll N; cin >> N;

  dp[0][0] = 1;
  rep(i, 0, N){
    char c; cin >> c;
    rep(h, 0, 8){
      // c is not chosen
      dp[i+1][h] = ( dp[i+1][h] + dp[i][h] ) % MOD;
      // c is chosen
      if(c == "atcoder"[h]) dp[i+1][h+1] = ( dp[i+1][h+1] + dp[i][h] ) % MOD;
    }
  }

  cout << dp[N][7] << endl;
  return 0;
}