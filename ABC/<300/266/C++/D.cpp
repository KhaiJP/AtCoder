#include<iostream>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

ll dp[100010][10], X[100010], A[100010], N, answer;

int main(){
  cin >> N;
  rep(i, 0, N){
    ll t, x, a; cin >> t >> x >> a;
    X[t] = x, A[t] = a;
  }
  rep(t, 0, 100001)rep(pit, 0, 5) dp[t][pit] = -1;
  dp[0][0] = 0;
  
  rep(t, 0, 100001)rep(pit, 0, 5)if(dp[t][pit] != -1){
    if(pit == X[t]) dp[t][pit] += A[t];
    rep(next, 0, 5)if(abs(next - pit) <= 1){
      dp[t+1][next] = max(dp[t+1][next], dp[t][pit]);
    }
  }
  
  rep(pit, 0, 5) answer = max(answer, dp[100001][pit]);
  cout << answer << endl;
  return 0;
}