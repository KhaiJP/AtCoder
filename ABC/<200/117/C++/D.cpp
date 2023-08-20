#include<iostream>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

ll A[100010], dp[65][2];
const ll INF = 1000000000000000, ll1 = 1;


int main(){
  ll N, K; cin >> N >> K;
  rep(i, 0, N) cin >> A[i];
  rep(i, 0, 65)rep(j, 0, 2) dp[i][j] = -INF;

  dp[0][0] = 0;

  rep(i, 0, 64)rep(j, 0, 2)if(dp[i][j] >= 0){
    ll flag1 = ll1 << (63 - i);

    ll zeros = 0, ones = 0;
    rep(i, 0, N){
      if(A[i] & flag1) ++ones;
      else ++zeros;
    }


    int j2 = j;
    if(K & flag1) j2 = 1;
    dp[i + 1][j2] = max(dp[i + 1][j2], dp[i][j] + ones * flag1);

    if( (K & flag1) || j == 1){
      dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + zeros * flag1);
    }
  }

  cout << max(dp[64][0], dp[64][1]) << endl;
  return 0;
}