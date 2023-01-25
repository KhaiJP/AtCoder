#include<iostream>
#include<vector>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int dp[123][112345];
const int inf32 =  1000000000+7;

int main(){
  int N; cin >> N;
  rep(i,0,N+1)rep(j,0,112345) dp[i][j] = inf32;
  dp[0][0] = 0;
  rep(i,0,N){
    int T; cin >> T;
    rep(j,0,112345){
      if(dp[i][j] == inf32) continue;
      dp[i+1][j+T] = min(dp[i+1][j+T], dp[i][j]);
      dp[i+1][j]   = min(dp[i+1][j], dp[i][j]+T);
    }
  }
  int answer = inf32;
  rep(i,0,112345) answer = min(answer, max(i, dp[N][i]));
  cout << answer << endl;
  
  return 0;
}