#include<iostream>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define N_MAX 110
#define W_MAX 100010
#define INF 1000000000+7

// dp[i][cw] : maximum total value choosing up to item i
ll dp[N_MAX][W_MAX], w[N_MAX], v[N_MAX];

int main(){
  // input
  int N, W; cin >> N >> W;
  rep(i, 0, N) cin >> w[i] >> v[i];
  
  // dp initialization. cw : current weight
  rep(i, 0, N+1)rep(cw, 0, W+1) dp[i][cw] = -1;
  dp[0][0] = 0;


  rep(i, 0, N)rep(cw, 0, W+1){
    // dp[i][cw] = -1  -> (i, cw) pair cannot be realised
    if( dp[ i ][ cw ] == -1 ) continue;
    // when item i is NOT taken
    dp[ i + 1 ][ cw ]  =  max(dp[ i + 1 ][ cw ], dp[ i ][ cw ]);
    // when item i is taken
    if( cw + w[i] > W ) continue;
    dp[ i + 1 ][ cw + w[i] ]  =  max( dp[ i + 1 ][ cw + w[i] ],  dp[ i ][ cw ] + v[ i ]);
  }

  // find the maximum
  ll answer = 0;
  rep(cw, 0, W+1) answer = max(answer, dp[N][cw]);
  
  cout << answer << endl;
  return 0;
}