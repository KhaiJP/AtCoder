#include<iostream>
using namespace std;
typedef int64_t ll;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

ll A, dp[100010][2];

int main(){
  ll N; cin >> N;
  cin >> A;
  dp[1][0] = A, dp[1][1] = -A;
  // cout << dp[1][0] << ' ' << dp[1][1] << '\n';
  rep(i,2,N){
    cin >> A;
    dp[i][0] = max(dp[i-1][0] + A, dp[i-1][1] - A);
    dp[i][1] = max(dp[i-1][0] - A, dp[i-1][1] + A);
    // cout << dp[i][0] << ' ' << dp[i][1] << '\n';
  }
  cin >> A;
  dp[N][0] = dp[N-1][0] + A, dp[N][1] = dp[N-1][1] - A;
  // cout << dp[N][0] << ' ' << dp[N][1] << '\n';
  cout << max(dp[N][0], dp[N][1]) << endl;
  return 0;
}