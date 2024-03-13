#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

// no need but solve by dp
int N, K, dp[55][55], l[55], inf=1e9;

int main(){
  rep(n, 0, 55)rep(k, 0, 55) dp[n][k] = -inf;
  dp[0][0] = 0;

  cin >> N >> K;
  rep(i, 0, N) cin >> l[i];

  rep(n, 0, N)rep(k, 0, K+1)if(dp[n][k] > -inf){
    dp[n+1][k] = max(dp[n+1][k], dp[n][k]);
    dp[n+1][k+1] = max(dp[n+1][k+1], dp[n][k] + l[n]);
  }

  cout << dp[N][K] << endl;
  return 0;
}