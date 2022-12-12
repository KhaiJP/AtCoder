#include<iostream>
#include<vector>
#define rep(i,n) for(int i=0; i<(n); ++i)
#define ll long long
using namespace std;

int main(){
  ll W; cin >> W;
  ll N, K; cin >> N >> K;
  vector<ll> A(N), B(N);
  rep(i,N) cin >> A[i] >> B[i];
  
  // dp[n][w]: maximum value upto A[1]~A[n-1] with width w
  vector dp(N+1, vector(K+1, vector<ll>(W+1, -1)));
  dp[0][0][0] = 0;
  rep(n,N)rep(k,K+1)rep(w, W+1){
    if(dp[n][k][w]==-1) continue;
    // A[n] is not taken
    dp[n+1][k][w] = max(dp[n+1][k][w], dp[n][k][w]);
    // A[n] is taken
    if(w+A[n] <= W && k != K){
      dp[n+1][k+1][w+A[n]] = max(dp[n+1][k+1][w+A[n]],
                            dp[n][k][w]+B[n]);
    }
  }
  ll M = 0; rep(k,K+1)rep(w,W+1) if(M < dp[N][k][w]) M = dp[N][k][w];
  cout << M << '\n' << endl;
  return 0;
}