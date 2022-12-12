#include<iostream>
#include<numeric>
#include<vector>
#define rep(i,s,n) for(int i=s; i<(n); ++i)
using namespace std;

int main(){
  const int inf = 1e9;
  int N, Ma, Mb; cin >> N >> Ma >> Mb;
  int mab = 10;
  vector dp(N+1, vector(N*mab+1, vector<int>(N*mab+1, inf)));
  dp[0][0][0] = 0;
  rep(n, 0, N){
    int a_, b_, c_; cin >> a_ >> b_ >> c_;
    rep(a, 0, N*mab+1) rep(b, 0, N*mab+1){
      if(dp[n][a][b]==inf)continue;
      dp[n+1][a][b] = min(dp[n+1][a][b],   dp[n][a][b]);
      dp[n+1][a+a_][b+b_] = min(dp[n+1][a+a_][b+b_],   dp[n][a][b]+c_);
    }
  }
  int a = Ma, b = Mb;
  int ans = inf;
  while(a < N*mab + 1 && b <N*mab + 1){
    ans = min(ans, dp[N][a][b]);
    a += Ma; b += Mb;
  }
  cout << (ans!=inf ? ans : -1) << endl;
  return 0;
}