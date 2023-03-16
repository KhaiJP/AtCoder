#include<iostream>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define N_MAX 3001
ll A[N_MAX], B[N_MAX], dp[N_MAX][N_MAX], pfx[N_MAX];

ll MOD = 998244353;

int main(){
  int N; cin >> N;
  rep(i, 0, N) cin >> A[i];
  rep(i, 0, N) cin >> B[i];

  dp[0][0] = 1;
  rep(i, 0, N){
    pfx[0] = dp[i][0];
    rep(c, 1, B[i]+1) pfx[c] = pfx[c-1] + dp[i][c];

    rep(c, A[i], B[i]+1) dp[i+1][c] = pfx[c] % MOD;
  }

  ll answer = 0;
  rep(c,0,N_MAX) answer = ( answer + dp[N][c]) % MOD;
  cout << answer << endl;

  return 0;
}