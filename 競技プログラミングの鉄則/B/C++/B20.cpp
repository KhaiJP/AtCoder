#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int N, M, dp[2010][2010];
string S, T;

int main(){
  cin >> S >> T;
  N = S.size(), M = T.size();

  rep(i, 0, N+1)rep(j, 0, M+1){
    if(i >= 1 && j >= 1 && S[i-1] == T[j-1]){
      dp[i][j] = min({dp[i-1][j] + 1, dp[i][j-1] + 1, dp[i-1][j-1]});
    }
    else if(i >= 1 && j >= 1){
      dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
    }
    else if(i >= 1){
      dp[i][j] = dp[i-1][j] + 1;
    }
    else if(j >= 1){
      dp[i][j] = dp[i][j-1] + 1;
    }
  }

  cout << dp[N][M] << endl;
  return 0;
}