#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int dp[100010];

int main(){
  int N; cin >> N;
  rep(n, 1, 100010) dp[n] = n;

  rep(n, 0, N){
    for(int p6 = 1; n + p6 <= N; p6 *= 6) dp[n + p6] = min(dp[n + p6], dp[n] + 1);
    for(int p9 = 1; n + p9 <= N; p9 *= 9) dp[n + p9] = min(dp[n + p9], dp[n] + 1);
  }

  cout << dp[N] << endl;
  return 0;
}