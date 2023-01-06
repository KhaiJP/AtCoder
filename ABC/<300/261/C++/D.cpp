#include <iostream>
#include <vector>
#include <unordered_map>
typedef int64_t ll;
#define rep(i, s, t) for (ll i = (s); i < (t); ++i)
using namespace std;

int main(){
  ll N, M; cin >> N >> M;
  vector<int> X(N+1); rep(i,1,N+1) cin >> X[i];
  unordered_map<ll, ll> CY;
  rep(i,0,M){
    ll C, Y; cin >> C >> Y;
    CY[C] += Y;
  }
  vector DP(N+1, vector<ll>(N+1, -1));

  DP[0][0] = 0;
  rep(n,0,N)rep(c,0,N){
    if(DP[n][c]==-1) continue;
    // when head
    DP[n+1][c+1] = max(DP[n+1][c+1], DP[n][c]+X[n+1]+CY[c+1]);
    // when tail
    DP[n+1][0]   = max(DP[n+1][0], DP[n][c]); 
  }
  ll answer = 0;
  rep(c,0,N+1) answer = max(answer, DP[N][c]);
  cout << answer << endl;
  return 0;
}