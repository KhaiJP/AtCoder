#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define N_MAX 100010
#define INF 1000000000+7

// dp[j] : minimum cost to stand on Stone j 
int dp[N_MAX], h[N_MAX];

int main(){
  int N, K; cin >> N >> K;
  rep(i, 1, N+1) cin >> h[i];
  rep(i, 2, N+1) dp[i] = INF;

  rep(i, 1, N)rep(k, 1, K+1) dp[i+k] = min(dp[i+k],  dp[i] + abs(h[i] - h[i+k]));
  
  cout << dp[N] << endl;
  return 0;
}