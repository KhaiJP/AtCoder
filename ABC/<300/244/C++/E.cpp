#include<iostream>
#include<vector>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

vector<ll> E[2010];
ll dp[2010][2010][2];
ll const MOD = 998244353;

int main(){
  int N, M, K, S, T, X; cin >> N >> M >> K >> S >> T >> X;
  rep(i, 0, M){
    int U, V; cin >> U >> V;
    E[U].push_back(V), E[V].push_back(U);
  }

  dp[0][S][0] = 1;

  // i : the index of A, u : the node Ai, isEven : if A0~Ai contains even number of X
  rep(i, 0, K)rep(u, 1, N+1)rep(isEven, 0, 2)if(dp[i][u][isEven] != 0){
    for(ll v : E[u]){
      int c = isEven;
      if(v == X) c = 1 - c;
      dp[i+1][v][c] = (dp[i+1][v][c] + dp[i][u][isEven]) % MOD;
    }
  }

  cout << dp[K][T][0] << endl;
  return 0;
}