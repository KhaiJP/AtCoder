#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define N_MAX 100010
#define INF 1000000000+7

// dp[j] : minimum cost to stand on Stone j 
int dp[N_MAX], h[N_MAX];

int main(){
  int N; cin >> N;
  rep(i, 1, N+1) cin >> h[i];
  rep(i, 2, N+1) dp[i] = INF;

  rep(i, 1, N){
    dp[i+1] = min(dp[i+1], dp[i] + abs(h[i] - h[i+1]));
    dp[i+2] = min(dp[i+2], dp[i] + abs(h[i] - h[i+2]));
  }
  
  cout << dp[N] << endl;
  return 0;
}