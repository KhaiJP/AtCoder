#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
typedef int64_t ll;
#define rep(i, s, t) for (int i = (s); i < (t); ++i)
#define fore(a, v) for(auto a : v)
using Edges = unordered_map<ll, vector<ll>>;

const int UL = 1000000;

int dfs(Edges &E, vector<bool> &visited, ll u){
  ll result = 1;
  visited[u] = true;

  fore(v, E[u]){
    if(visited[v]) continue;
    result += dfs(E, visited, v);
    if(result >= UL) return UL;
  }
  
  visited[u] = false;
  return result;
}

int main(){
  ll N, M; cin >> N >> M;
  // adjacency map: node u -> adjacency nodes of u
  Edges E;
  rep(i,0,M){
    ll u, v; cin >> u >> v; --u, --v;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  vector<bool> visited(N, false);
  cout << dfs(E, visited, 0) << endl;
  return 0;
}