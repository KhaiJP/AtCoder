#include<iostream>
#include<queue>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

// solve by combo of bfs and binary search
// finding the answer by binary search with the criterion is given by bfs
// bfs is to be done over N points whose edge weights are given by minimum S to jump from i to j
ll x[210], y[210], P[210];
ll adjacent[210][210];
bool visited[210];

int main(){
  ll N; cin >> N;
  rep(i, 0, N) cin >> x[i] >> y[i] >> P[i];
  
  rep(i, 0, N)rep(j, 0, N){
    ll d = abs(x[i] - x[j]) + abs(y[i] - y[j]);
    ll S = (d + P[i] - 1) / P[i];
    adjacent[i][j] = S;
  }

  // find the answer by binary search
  ll l = 0, S = 4e9+1;
  while(l + 1 < S){
    ll m = (l + S) / 2;
    bool allvisited = false;
    // check if there is a node that can move to all the nodes
    rep(i, 0, N){
      // initialize the boolean table
      rep(u, 0, N) visited[u] = false;
      
      // bfs
      queue<ll> q; q.push(i);
      visited[i] = true;
      while(q.size()){
        ll u = q.front(); q.pop();
        rep(v, 0, N)if(adjacent[u][v] <= m && !visited[v]){
          visited[v] = true;
          q.push(v);
        }
      }
      bool flag = true;
      rep(u, 0, N) flag = flag && visited[u];
      if(flag){
        allvisited = true;
        break;
      }
    }

    // if all nodes can be visited, m big enough; r <- m
    if(allvisited) S = m;
    else           l = m;
  }

  cout << S << endl;
  return 0;
}
