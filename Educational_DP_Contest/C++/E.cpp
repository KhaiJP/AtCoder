#include<iostream>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define N_MAX 110
#define NV_MAX 100010
#define INF 1000000000+7

// dp[i][cv] : minimum total weight choosing up to item i with current value cv
ll dp[N_MAX][NV_MAX], w[N_MAX], v[N_MAX];

int main(){
  int N, W; cin >> N >> W;
  // tot_v_sum = \sum_{i=0}^{N-1} v_i = v_0:N-1
  int tot_v_sum = 0;
  rep(i, 0, N){
    cin >> w[i] >> v[i];
    tot_v_sum += v[i];
  }
  
  // dp initialization.  cv : current value
  rep(i, 0, N+1)rep(cv , 0, tot_v_sum+1) dp[i][cv] = INF;
  dp[0][0] = 0;

  rep(i, 0, N)rep(cv, 0, tot_v_sum+1){
    // dp[i][cv] > W -> no need to consider
    if( dp[ i ][ cv ] > W ) continue;
    dp[ i + 1 ][ cv ]  =  min(dp[ i + 1 ][ cv ], dp[ i ][ cv ]);
    dp[ i + 1 ][ cv + v[i] ]  =  min( dp[ i + 1 ][ cv + v[i] ],  dp[ i ][ cv ] + w[ i ]);
  }

  // find the maximum total value
  int answer = 0;
  rep(cv, 0, tot_v_sum + 1)if(dp[N][cv] <= W) answer = cv;
  
  cout << answer << endl;
  return 0;
}