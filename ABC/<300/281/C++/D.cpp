#include<iostream>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define chmax(a, b) a = max(a, b)

ll A[110], dp[110][110][110];

int main(){
  int N, K, D; cin >> N >> K >> D;
  rep(i, 0, N) cin >> A[i];
  
  rep(i, 0, N)rep(k, 0, K+1)rep(r, 0, D) dp[i][k][r] = -1;
  dp[0][0][0] = 0;
  
  rep(i, 0, N)rep(k, 0, K+1)rep(r, 0, D)if(dp[i][k][r] != -1){
    // A[i] is not chosen
    chmax( dp[i+1][k][r], dp[i][k][r] );
    if(k == K) continue;
    // A[i] is chosen
    chmax( dp[i+1][k+1][(r+A[i])%D], dp[i][k][r] + A[i]);
  }
  
  cout << dp[N][K][0] << endl;
  return 0;
}