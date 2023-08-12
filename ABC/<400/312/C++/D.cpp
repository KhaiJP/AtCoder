#include<iostream>
#include<string>
#include<atcoder/all>
using namespace std;
using mint = atcoder::modint998244353;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

mint dp[3010][3010];

int main(){
  string S; cin >> S;
  int N = S.size();
  
  dp[0][0] = 1;
  rep(i, 0, N)rep(j, 0, N/2+2)if(dp[i][j].val() != 0){
    if(S[i] == '?'){
      if(j) dp[i+1][j-1] += dp[i][j];
      dp[i+1][j+1] += dp[i][j];
    }
    
    if(S[i] == ')')if(j){
      dp[i+1][j-1] += dp[i][j];
    }
    
    if(S[i] == '('){
      dp[i+1][j+1] += dp[i][j];
    }
  }
  
  cout << dp[N][0].val() << endl;
  return 0;
}