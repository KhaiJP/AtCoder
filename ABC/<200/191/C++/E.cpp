#include<iostream>
#include<set>
#include<queue>
using namespace std;
using P = pair<int, int>;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

set<int> E[2010];
int N, M, dist[2010], W[2020][2020], inf = 1e9;

void Dijkstra(int s){
  // initialize the distance from s; source
  rep(u, 1, N+1) dist[u] = inf;
  priority_queue<P> q;
  q.push({0, s});
  // main Dijkstra part
  while(q.size()){
    int d = -q.top().first, u = q.top().second;
    q.pop();
    if(d > dist[u]) continue;
    for(auto v : E[u])if(d + W[u][v] < dist[v]){
      dist[v] = d + W[u][v];
      q.push({-dist[v], v});
    }
  }
  cout << (dist[s] < inf ? dist[s] : -1) << endl;
  return ;
}

int main(){
  cin >> N >> M;
  // initialize W; the weight of the edge from u to v
  rep(u, 0, 2020)rep(v, 0, 2020) W[u][v] = inf;
  // set edges
  rep(i, 0, M){
    int a, b, c; cin >> a >> b >> c;
    E[a].insert(b);
    W[a][b] = min(W[a][b], c);
  }
  // solve each case
  rep(s, 1, N+1) Dijkstra(s);
  
  return 0;
}