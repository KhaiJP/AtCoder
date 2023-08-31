#include<iostream>
#include<string>
#include<atcoder/all>
using namespace std;
using mint = atcoder::modint1000000007;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

mint dp[100010][15];

int main(){
  string S; cin >> S;
  int N = S.size();
  
  dp[0][0] = 1;
  rep(i, 0, N)rep(r, 0, 13)if(dp[i][r].val() != 0){
    if(S[i] == '?')rep(k, 0, 10){
      dp[i+1][(10*r+k)%13] += dp[i][r];
    }
    else{
      int n = S[i] - '0';
      dp[i+1][(10*r+n)%13] += dp[i][r];
    }
  }
  
  cout << dp[N][5].val() << endl;
  return 0;
}