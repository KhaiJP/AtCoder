#include<iostream>
#include<vector>
#include<unordered_map>
#include<deque>
using namespace std;
typedef int64_t ll;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define fore(a, v) for(auto a : v)

int main(){
  int N; cin >> N;

  // make the tree graph
  unordered_map< int, vector<pair<int, int>> > Edges;
  rep(i,0,N-1){
    int a, b, c; cin >> a >> b >> c; --a, --b, c;
    Edges[a].push_back({b,c});
    Edges[b].push_back({a,c});
  }
  
  int Q, K; cin >> Q >> K; --K;

  // find distance from K to any node v by bfs
  vector<ll> dist(N, 0);
  vector<bool> visited(N, false);
  visited[K] = true;
  deque<int> dq;
  dq.push_back(K);
  while(!dq.empty()){
    int &u = dq.front(); dq.pop_front();
    fore(v_p, Edges[u]){
      int &v = v_p.first; int &w = v_p.second;
      if(visited[v]) continue;
      visited[v] = true;
      dist[v] = dist[u] + (ll)w;
      dq.push_back(v);
    }
  }

  // deal with queries
  rep(q,0,Q){
    int x, y; cin >> x >> y; --x, --y;
    cout << dist[x] + dist[y] << '\n';
  }
  cout << endl;
  return 0;
}