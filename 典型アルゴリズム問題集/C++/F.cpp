#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

vector<ll> E[100010];
map<pair<ll, ll>, ll> W;

ll DJP(ll n){
  vector<bool> visited(n, false);
  visited[0] = true;
  --n;

  priority_queue<pair<ll, ll>> pq;
  for(auto v : E[0]) pq.push({-W[{0, v}], v});

  ll total_cost = 0;
  while(n){
    ll w = -pq.top().first, u = pq.top().second;
    pq.pop();

    if(visited[u]) continue;
    visited[u] = true;
    total_cost += w;
    --n;

    for(auto v : E[u])if(!visited[v]) pq.push({-W[{u, v}], v});
  }

  return total_cost;
}

int main(){
  ll N, M; cin >> N >> M;
  rep(i, 0, M){
    int u, v, c; cin >> u >> v >> c;
    if(W[{u,v}] == 0){
    E[u].push_back(v);
    E[v].push_back(u);
    }
    W[{u, v}] = W[{v, u}] = c;
  }

  cout << DJP(N) << endl;
  return 0;
}