#include<iostream>
#include<vector>
#define rep(i,s,t) for(int i=(s); i<(t); ++i)
using namespace std;

int main(){
  int N, M; cin >> N >> M;
  vector<int64_t> A(N+1); rep(i,1,N+1) cin >> A[i];
  // initialized by sufficiently small number
  vector dp(N+1, vector<int64_t>(M+1, -100000000000000000));
  dp[0][0] = 0;
  rep(n, 0, N)rep(m, 0, M+1){
    if(dp[n][m] == -100000000000000000) continue;
    // A[n+1] is not taken
    dp[n+1][m] = max(dp[n+1][m], dp[n][m]);
    // A[n+1] is taken. 
    if(m < M) dp[n+1][m+1] = max(dp[n+1][m+1], dp[n][m]+(m+1)*A[n+1]);
  }
  cout << dp[N][M] << endl;
  return 0;
}