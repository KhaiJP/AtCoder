#include<iostream>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

ll MOD = 998244353;

ll dp[200020][2], cards[200020][2];

int main(){
  int N; cin >> N;
  rep(i, 1, N+1) cin >> cards[i][0] >> cards[i][1];

  dp[1][0] = 1, dp[1][1] = 1;
  rep(i, 1, N)rep(pre, 0, 2)rep(nxt, 0, 2){
    if(cards[i][pre] != cards[i+1][nxt]) dp[i+1][nxt] = (dp[i+1][nxt] + dp[i][pre]) % MOD;
  }

  cout << (dp[N][0] + dp[N][1]) % MOD << endl;
  return 0;
}