#include<iostream>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

const ll MOD = 998244353;
ll dp[100010][10];
int A[100010];

int main(){
  int N; cin >> N;
  rep(i, 0, N) cin >> A[i];
  
  dp[0][A[0]] = 1;
  rep(i, 0, N-1)rep(j, 0, 10){
    // F
    dp[i+1][(j + A[i+1]) % 10] = ( dp[i+1][(j + A[i+1]) % 10] + dp[i][j] ) % MOD;
    // G
    dp[i+1][(j * A[i+1]) % 10] = ( dp[i+1][(j * A[i+1]) % 10] + dp[i][j] ) % MOD;
  }

  rep(k, 0, 10) cout << dp[N-1][k] << endl;
  return 0;
}