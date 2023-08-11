#include<iostream>
#include<vector>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)
#define chmax(a, b) a = max(a, b)

vector<ll> E[200010];
ll A[200010], dp[200010][2], in[200010], inf = 1e17, answer = -inf;

int main(){
  ll N, M; cin >> N >> M;
  rep(i, 1, N+1) cin >> A[i];

  rep(i, 0, M){
    ll X, Y; cin >> X >> Y;
    E[X].push_back(Y);
    ++in[Y];
  }
  rep(i, 1, N+1)if(in[i] == 0) E[0].push_back(i);

  rep(u, 0, N+1)rep(j, 0, 2) dp[u][j] = -inf;
  rep(u, 0, N)for(auto v : E[u]){
    chmax(dp[v][0], max(dp[u][0], -A[v]));
    chmax(dp[v][1], dp[u][0] + A[v]);
  }

  rep(u, 1, N+1)if(in[u] > 0) chmax(answer, dp[u][1]);
  cout << answer << endl;
  return 0;
}