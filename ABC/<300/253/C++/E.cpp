#include<iostream>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

const ll MOD = 998244353;
// naive DP -> O(NM^2) -> TLE. prefix sum accelerates to O(NM)
ll dp[1010][5010], pfx[5010];

int main(){
  ll N, M, K; cin >> N >> M >> K;

  // A1 can be whatever
  rep(m, 1, M+1) dp[1][m] = 1;

  rep(n, 2, N+1){
    // pfx[] initialization
    rep(m, 0, M+1) pfx[m] = 0;
    rep(m, 1, M+1) pfx[m] = pfx[m-1] + dp[n-1][m];

    rep(m, 1, M+1){
      if(m - K >= 1) dp[n][m] = (dp[n][m] + pfx[m - K]) % MOD;
      if(m + K <= M) dp[n][m] = (dp[n][m] + pfx[M] - pfx[m + K -1]) % MOD;
      // if K == 0, dp[n-1][m] is added twice -> needs subtraction
      if(K == 0) dp[n][m] -= dp[n-1][m];
    }
  }

  ll answer = 0; rep(m, 1, M+1) answer = (answer + dp[N][m]) % MOD;
  cout << answer << endl;
  return 0;
}