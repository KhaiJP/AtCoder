#include<iostream>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint998244353;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

mint dp[3010][3010];

int main(){
  string s; cin >> s;
  int N = s.size();
  dp[0][0] = 1;

  rep(i, 0, N)rep(j, 0, N+1){
    if(s[i] == '('){
      dp[i+1][j+1] += dp[i][j]; 
    }

    if(s[i] == ')'){
      if(j-1 >= 0) dp[i+1][j-1] += dp[i][j]; 
    }

    if(s[i] == '?'){
      dp[i+1][j+1] += dp[i][j]; 
      if(j-1 >= 0) dp[i+1][j-1] += dp[i][j]; 
    }
  }

  cout << dp[N][0].val() << endl;
  return 0;
}