#include<iostream>
#include<atcoder/dsu>
#include<deque>
#include<map>
#include<vector>
using namespace std;
using ll = int64_t;
using UF = atcoder::dsu;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

vector<ll> E[200010];
ll N, M;

// deque, map, vector require to be icluded
// array of vector<ll> E[N] must be declared globally
bool isBiGraph(vector<int> &V, vector<ll> &col0nodes, vector<ll> &col1nodes){
  // node : element of V; V is not supposed to 0 to V.size()-1
  map<ll, ll> node_to_index;
  rep(i, 0, V.size()) node_to_index[V[i]] = i;
  vector<ll> index_to_colour(V.size(), -1);

  index_to_colour[0] = 0;
  deque<ll> q; q.push_back(V[0]);
  while(q.size()){
    ll u = q.front(); q.pop_front();
    ll u_index = node_to_index[u];
    ll clr = index_to_colour[u_index];
    for(auto v : E[u]){
      ll v_index = node_to_index[v];
      // if adjacent node v is already coloured
      // adjacent colour is same -> not a bigraph
      if(index_to_colour[v_index] == clr) return false;
      // adjacent colour is different -> no need another inspection
      if(index_to_colour[v_index] == 1 - clr) continue;

      // in the case v is not coloured yet
      index_to_colour[v_index] = 1 - clr;
      q.push_back(v);
    }
  }
  
  for(auto u : V){
    ll u_index = node_to_index[u];
    ll clr = index_to_colour[u_index];
    if(clr == 0) col0nodes.push_back(u);
    if(clr == 1) col1nodes.push_back(u);
  }
  return true;
}

int main(){
  cin >> N >> M;
  UF uf(N);
  rep(i, 0, M){
    ll u, v; cin >> u >> v; --u, --v;
    E[u].push_back(v),  E[v].push_back(u);
    uf.merge(u, v);
  }

  bool flag = true;
  ll answer = N*(N-1)/2 - M;
  for(auto g : uf.groups()){
    vector<ll> col0, col1;
    bool tmp = isBiGraph(g, col0, col1);
    ll n0 = col0.size(), n1 = col1.size();
    answer -= n0*(n0-1)/2 + n1*(n1-1)/2; 
    flag = flag && tmp;
  }
  
  cout << (flag ? answer : 0) << endl;
  return 0;
}