#include<iostream>
using namespace std;
using ll = long long;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)
const ll MOD =  998244353;
ll  dp[51][2501];
int main(){
  ll N, M, K; cin >> N >> M >> K;
  dp[0][0] = 1;

  rep(i, 0, N)rep(j,0,K){
    if(dp[i][j] == 0) continue;
    rep(delta, 1, M+1){
      if(j + delta <= K){
        dp[i+1][j+delta] += dp[i][j]%MOD;
      }else{
        break;
      }
    }
  }

  ll answer = 0;
  rep(k, N, K+1) answer = (answer + dp[N][k])%MOD;

  cout << answer << endl;
  return 0;
}