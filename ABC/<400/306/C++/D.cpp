#include<iostream>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

const ll llinf =  100000000000000000;

ll dp[300010][2], X[300010], Y[300010];

int main(){
  ll N; cin >> N;
  rep(i, 0, N) cin >> X[i] >> Y[i];

  rep(i, 0, N)rep(j, 0, 2) dp[i][j] = -llinf;
  dp[0][0] = 0;
  rep(i, 0, N)rep(j, 0, 2){
    // skip i-th course
    dp[i+1][j] = max(dp[i+1][j], dp[i][j]);

    // have i-th course if possible
    if(X[i] == 0)           dp[i+1][0] = max(dp[i+1][0], dp[i][j] + Y[i]);
    if(X[i] == 1 && j == 0) dp[i+1][1] = max(dp[i+1][1], dp[i][j] + Y[i]);
  }

  cout << max(dp[N][0], dp[N][1]) << endl;
  return 0;
}