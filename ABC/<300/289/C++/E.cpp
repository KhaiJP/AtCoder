#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  int T; cin >> T;
  while(T--){
    int N, M; cin >> N >> M;

    // C preparation
    vector<int> C(N+1);
    rep(i, 1, N+1) cin >> C[i];
    
    // Edge preparation
    vector<vector<int>> E(N+1);
    rep(j, 0, M){
      int u, v; cin >> u >> v;
      E[u].push_back(v),  E[v].push_back(u);
    }
    
    // Apparent no-chance case
    if(C[1] == C[N] || E[1].empty() || E[N].empty()){
      cout << -1 << endl;
      continue;
    }

    // bfs preparation
    vector dist(N+1, vector<int>(N+1, 1e9));
    queue<pair<int, int>> q; q.push({1, N});
    dist[1][N] = 0;

    // bfs
    while(q.size()){
      int u1 = q.front().first, u2 = q.front().second;
      q.pop();
      int &d = dist[u1][u2];
      for(auto v1 : E[u1])for(auto v2 : E[u2]){
        if(d + 1 >= dist[v1][v2] || C[v1] == C[v2]) continue;
        dist[v1][v2] = d + 1;
        q.push({v1, v2});
      }
    }

    cout << ( dist[N][1] < 1e9 ? dist[N][1] : -1 ) << endl;
  }

  return 0;
}