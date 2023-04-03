#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;
using ll = int64_t;
using Edges = vector<vector<ll>>;
using Weights = map<pair<ll, ll>, ll>;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

// dist[i][j] : distance to node j from node u(= 0 if i =0, = N-1 if i = 1)
ll dist[2][100010];
bool visited[2][100010];
ll N, M;

void Dijkstra(vector<vector<ll>> &E, map<pair<ll, ll>, ll> &W, int mode){
  rep(i, 0, N) dist[mode][i] = 1000000007;
  int s = (N-1) * mode;
  dist[mode][s] = 0;
  priority_queue<pair<ll, ll>> q;
  q.push({-dist[mode][s], s});

  while(!q.empty()){
    ll d = -q.top().first, u = q.top().second;
    q.pop();

    if(visited[mode][u]) continue;
    else visited[mode][u] = true;

    for(auto v : E[u]){
      ll alt = W[{u, v}] + d;
      if(alt < dist[mode][v]){
        dist[mode][v] = alt;
        q.push({-dist[mode][v], v});
      }
    }
  }
}

int main(){
  cin >> N >> M;

  Edges E(N);
  Weights W;
  
  // graph spanning
  rep(i, 0, M){
    ll A, B, C; cin >> A >> B >> C; --A, --B;
    E[A].push_back(B);
    E[B].push_back(A);
    W[{A,B}] = W[{B, A}] = C;
  }

  // calculate distances to any node from node 0(mode = 0) and node N-1(mode = 1)
  rep(mode, 0, 2) Dijkstra(E, W, mode);
  // the answer is d_0,k(= dist[0][k]) + d_k,N-1(= d_N-1,k = dist[1][k])
  rep(k, 0, N) cout << dist[0][k] + dist[1][k] << '\n';

  cout << endl;
  return 0;
}