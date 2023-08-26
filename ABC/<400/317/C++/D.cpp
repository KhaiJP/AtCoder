#include<iostream>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define chmin(a, b) a = min((a), (b))

ll X[110], Y[110], Z[110], tZ, inf = 1e18;
// dp[i][j] : min # of people that have been swithed
//            up to i-th district with Takahashi has won j seats
ll dp[110][100010];

int main(){
  ll N; cin >> N;
  rep(i, 0, N) cin >> X[i] >> Y[i] >> Z[i];
  rep(i, 0, N) tZ += Z[i];

  // initialize dp table
  rep(i, 0, N+1)rep(j, 0, tZ+1) dp[i][j] = inf;
  dp[0][0] = 0;

  rep(i, 0, N)rep(j, 0, tZ+1)if(dp[i][j] < inf){
    if(X[i] > Y[i]){
      // no need switch
      chmin(dp[i+1][j + Z[i]], dp[i][j]);
    }else{
      // accept defeat
      chmin(dp[i+1][j], dp[i][j]);

      // switch some people to exceed the half of X+Y
      ll mid = (X[i] + Y[i]) / 2 + 1;
      chmin(dp[i+1][j + Z[i]], dp[i][j] + mid - X[i]);
    }
  }

  ll answer = inf;
  rep(j, tZ/2+1, tZ+1) chmin(answer, dp[N][j]);
  cout << answer << endl;
  return 0;
}