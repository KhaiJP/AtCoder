#include<iostream>
#include<string>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

ll const MOD = 1000000007;
ll dp[100010][9];
string const chokudai = "chokudaiA";

int main(){
  string S; cin >> S;
  ll N = S.size();
  
  dp[0][0] = 1;
  rep(i, 0, N)rep(j, 0, 9){
    dp[i+1][j] = (dp[i+1][j] + dp[i][j]) % MOD;
    if(S[i] == chokudai[j]){
      dp[i+1][j+1] = ( dp[i+1][j+1] + dp[i][j] ) % MOD;
    }
  }
  
  cout << dp[N][8] << endl;
  return 0;
}
