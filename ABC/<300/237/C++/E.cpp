#include<iostream>
#include<vector>
#include<queue>
using namespace std;
using ll = int64_t;
using P = pair<ll, int>;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)


vector<P> E[200010];
ll H[200010], dist[200010];
priority_queue<P> q;
bool visited[200010];

int main(){
  int N, M; cin >> N >> M;
  rep(u, 1, N+1) cin >> H[u];
  rep(i, 0, M){
    int u, v; cin >> u >> v;
    if(H[u] < H[v]){
      E[u].push_back({H[v] - H[u], v});
      E[v].push_back({0          , u});
    }
    else{
      E[u].push_back({0          , v});
      E[v].push_back({H[u] - H[v], u});
    }
  }

  ll answer = 0;
  rep(u, 2, N+1) dist[u] = 1e18;
  q.push({-dist[1], 1});
  while(q.size()){
    ll d = -q.top().first; int u = q.top().second; q.pop();
    if(visited[u]) continue;
    visited[u] = true;
    answer = max(answer, H[1] - H[u] - d);

    for(auto p : E[u]){
      int v = p.second;
      ll  w = p.first;
      if(d + w < dist[v]){
        dist[v] = d + w;
        q.push({-dist[v], v});
      }
    }
  }
  cout << answer << endl;
  return 0;
}