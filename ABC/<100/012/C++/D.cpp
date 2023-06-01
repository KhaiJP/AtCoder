#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int FW[310][310];
int const INF = 1000000007;

int main(){
  int N, M; cin >> N >> M;
  rep(i, 0, M){
    int a, b, t; cin >> a >> b >> t; --a, --b;
    FW[a][b] = FW[b][a] = t;
  }
  rep(u, 0, N)rep(v, 0, N)if(u != v && FW[u][v] == 0) FW[u][v] = INF;

  rep(k, 0, N)rep(u, 0, N)rep(v, 0, N){
    FW[u][v] = min(FW[u][v], FW[u][k] + FW[k][v]);
  }

  int max_d = INF;
  rep(u, 0, N){
    int u_max_d = 0;
    rep(v, 0, N) u_max_d = max(u_max_d, FW[u][v]);
    max_d = min(max_d, u_max_d);
  }

  cout << max_d << endl;
  return 0;
}