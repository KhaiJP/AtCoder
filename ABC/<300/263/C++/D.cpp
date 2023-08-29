#include<iostream>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)
#define chmin(a, b) a = min(a, b);

ll N, L, R;
ll A[200010], dp[200010][3];
ll inf = 2e18;

int main(){
  cin >> N >> L >> R;
  rep(i, 0, N) cin >> A[i];

  rep(i, 0, 200010)rep(s, 0, 3) dp[i][s] = inf;
  dp[0][0] = 0;

  rep(i, 0, N)rep(s, 0, 3){
    chmin(dp[i+1][2], dp[i][s] + R);
    if(s == 2) continue;

    chmin(dp[i+1][1], dp[i][s] + A[i]);
    if(s == 1) continue;

    chmin(dp[i+1][0], dp[i][s] + L);
  }

  ll answer = inf;
  rep(s, 0, 3) chmin(answer, dp[N][s]);
  cout << answer << endl;
  return 0;
}