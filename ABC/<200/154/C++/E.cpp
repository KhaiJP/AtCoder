#include<iostream>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

string N;
ll K, dp[2][110][5];

int main(){
  cin >> N >> K;
  ll M = N.size();
  
  dp[0][0][0] = 1;
  rep(isless, 0, 2)rep(dit, 0, M)rep(k, 0, K+1)if(dp[isless][dit][k]>0){
    ll d = N[dit] - '0';
    rep(next, 0, 10)if(d >= next || isless == 1){
      ll n_isless = (next < d ? 1 : isless);
      ll n_k      = k + (next > 0);

      dp[n_isless][dit + 1][n_k] += dp[isless][dit][k]; 
    }
  }
  
  cout << dp[0][M][K] + dp[1][M][K] << endl;
  return 0;
}