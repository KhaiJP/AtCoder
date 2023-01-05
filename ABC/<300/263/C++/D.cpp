#include<iostream>
#include<vector>
typedef int64_t ll;
#define rep(i, s, t) for (ll i = (s); i < (t); ++i)
#define ren(i, s, t) for (ll i = (s); i >= (t); --i)
using namespace std;

int main(){
  int N, L, R; cin >> N >> L >> R;
  vector<ll>  A(N+1); rep(i,1,N+1) cin >> A[i];
  vector DP(N+1, vector<ll>(3, 1000000000000000000));
  DP[0][0] = 0;
  rep(i, 0, N)rep(s, 0, 3){
    if(DP[i][s] == 1000000000000000000) continue;
    if( true ) DP[i+1][2] = min(DP[i+1][2], DP[i][s] + R);
    if(s != 2) DP[i+1][1] = min(DP[i+1][1], DP[i][s] + A[i+1]);
    if(s == 0) DP[i+1][0] = min(DP[i+1][0], DP[i][s] + L);
  }
  ll answer = 1000000000000000000;
  rep(s,0,3) answer = min(answer, DP[N][s]);
  cout << answer << '\n';
  return 0;
}