#include<iostream>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)
const ll MOD = 998244353;

ll dp[1000010][10];

int main(){
  int N; cin >> N;
  
  rep(j, 1, 10) dp[1][j] = 1;
  rep(i, 1, N)rep(j, 1, 10){
    dp[i+1][j] = (dp[i+1][j] + dp[i][j]) % MOD;
    if(j != 9) dp[i+1][j+1] = (dp[i+1][j+1] + dp[i][j]) % MOD;
    if(j != 1) dp[i+1][j-1] = (dp[i+1][j-1] + dp[i][j]) % MOD;
  }

  ll answer = 0;
  rep(j, 1, 10) answer = (answer + dp[N][j]) % MOD;

  cout << answer << endl;
  return 0;
}