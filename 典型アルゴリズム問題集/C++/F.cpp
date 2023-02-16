#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<queue>
using namespace std;
using ll = int64_t;
using Edges = unordered_map<ll, vector<ll>>;
using Weights = map<pair<ll, ll>, ll>;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define fore(a, v) for(auto a : v)

template<typename T>
T DJP(vector<T> &V, Edges &E, Weights &W){
  T sizeV = V.size();
  vector<bool> visited(sizeV, false);
  visited[0] = true;
  --sizeV;
  
  priority_queue< pair<T, T> > q;
  fore(v, E[0]) q.push({-W[{0,v}], v});
  
  T total_cost = 0;
  while(sizeV){
    T w = -q.top().first,  u =  q.top().second;
    q.pop();

    if(visited[u]) continue;
    visited[u] = true;
    total_cost += w;
    --sizeV;

    for(auto v : E[u]){
      if(visited[v]) continue;
      q.push({-W[{u,v}], v});
    }
  }

  return total_cost;
}

int main(){
  ll N, M; cin >> N >> M;
  vector<ll> V(N); rep(i,0,N) V[i] = i;
  Edges E;
  Weights W;

  rep(i,0,M){
    ll u, v, c; cin >> u >> v >> c;
    if(W.count({u, v}) == 0){
      E[u].push_back(v);
      E[v].push_back(u);
    }
    W[{u,v}] = W[{v, u}] = c;
  }

  ll answer = DJP(V, E, W);
  cout << answer << endl;
  return 0;
}