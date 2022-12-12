#include<iostream>
#include<vector>
#define rep(i,n) for(int i=0; i<(n); ++i)
using namespace std;

int main(){
  int N, K, D; cin >> N >> K >> D;
  vector<int> A(N); rep(i,N) cin >> A[i];
  vector dp(N+1, vector(K+1, vector<long long>(D, -1)));
  dp[0][0][0] = 0;
  
  rep(n,N) rep(k,K+1) rep(d,D){
    if(dp[n][k][d]==-1) continue;
    // when A[n] is NOT taken
    dp[n+1][k][d] = max(dp[n+1][k][d], dp[n][k][d]);
    // when A[n] is taken
    if(k != K){
      dp[n+1][k+1][(d+A[n])%D] = max(dp[n+1][k+1][(d+A[n])%D], 
                                     dp[n][k][d]+A[n]);
    }
  }
  cout << dp[N][K][0] << endl;
  return 0;
}