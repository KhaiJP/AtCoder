#include<iostream>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define chmax(a, b) a = max(a, b)

ll x[1010], y[1010], z[1010], dp[1010][1010], N , M, inf = 2e18;;

int main(){
  cin >> N >> M;
  rep(i, 0, N) cin >> x[i] >> y[i] >> z[i];
  
  
  ll answer = -inf;
  rep(cx, 0, 2)rep(cy, 0, 2)rep(cz, 0, 2){
    // make 0 -> -1 and 1 -> 1
    ll kx = 2*cx - 1,  ky = 2*cy - 1,  kz = 2*cz - 1;
    
    rep(i, 0, 1010)rep(j, 0, 1010) dp[i][j] =-inf;
    dp[0][0] = 0;
    
    rep(i, 0, N)rep(j, 0, M+1)if(dp[i][j] > -inf){
      chmax( dp[i+1][j], dp[i][j] );
      if(j == M) continue;
      ll delta = kx * x[i]  +  ky * y[i]  +  kz * z[i];
      chmax( dp[i+1][j+1], dp[i][j] + delta );
    }
    
    chmax(answer, dp[N][M]);
  }
  
  cout << answer << endl;
  return 0;
}