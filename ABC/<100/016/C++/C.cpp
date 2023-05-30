#include<iostream>
#include<set>
#include<vector>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

set<int> E[11];
int const INF = 100;

int main(){
  int N, M; cin >> N >> M;
  rep(i, 0, M){
    int A, B; cin >> A >> B; --A, --B;
    E[A].insert(B), E[B].insert(A);
  }

  vector FW(N, vector<int>(N, INF));
  rep(u, 0, N){
    for(auto v : E[u])FW[u][v] = 1, FW[v][u] = 1;
    FW[u][u] = 0;
  }

  rep(k, 0, N)rep(u, 0, N)rep(v, 0, N){
    FW[u][v] = min(FW[u][v], FW[u][k] + FW[k][v]);
  }

  rep(u, 0, N){
    // number of nodes that distance from u is 2
    int n_d2 = 0;
    rep(v, 0, N) n_d2 += FW[u][v] == 2;
    cout << n_d2 << endl;
  }

  return 0;
}