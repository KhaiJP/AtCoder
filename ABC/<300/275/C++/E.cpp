#include<iostream>
#include<atcoder/all>
using namespace std;
using mint = atcoder::modint998244353;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

mint dp[1010][1010];

int main(){
  int N, M, K; cin >> N >> M >> K;
  mint inv_M = mint(1) / M;

  dp[0][0] = 1;
  rep(k, 0, K)rep(n, 0, N+1){
    // already reached the gaol
    if(n == N){
      dp[k+1][n] += dp[k][n];
      continue;
    }
    rep(l, 1, M+1){
      int nn = n + l;
      if(nn > N) nn = N - (nn - N);
      dp[k+1][nn] += dp[k][n] * inv_M; 
    }
  }

  cout << dp[K][N].val() << endl;
  return 0;
}