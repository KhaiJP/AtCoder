#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef int64_t ll;
#define rep(i,s,t) for(int i = (s); i < (t); ++i)

int main(){
  int N; cin >> N;
  vector<string> S(N+1); rep(i,1,N+1) cin >> S[i];
  vector dp(N+1, vector<ll>(2, -1));
  dp[0][0] = 1; dp[0][1] = 1;
  rep(i,1,N+1){
    if(S[i] == "AND"){
      dp[i][1] = max(dp[i][1], dp[i-1][1]);
      dp[i][0] = max(dp[i][0], dp[i-1][1] + 2*dp[i-1][0]);
    }else{
      dp[i][1] = max(dp[i][1], 2*dp[i-1][1] + dp[i-1][0]);
      dp[i][0] = max(dp[i][0], dp[i-1][0]);
    }
  }
  cout << dp[N][1] << endl;
  return 0;
}