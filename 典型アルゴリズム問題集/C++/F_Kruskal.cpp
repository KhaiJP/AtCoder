#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using ll = int64_t;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

vector<int> E[100010];
bool spanned[100010];
map<pair<int, int>, int> W;
dsu uf(100010);

ll Kruskal(){
  priority_queue<pair<int, int>> q;
  for(auto v : E[0]) q.push( { -W[{0, v}], v} );
  spanned[0] = true;

  ll spanning_cost = 0;

  while(!q.empty()){
    int w = -q.top().first, u = q.top().second;
    q.pop();
    
    if(spanned[u]) continue;

    for(auto v : E[u])if(!spanned[v]){
      q.push( {-W[{u, v}], v} );
    }
    spanning_cost += w * (!uf.same(0, u));
    uf.merge(0, u);
    spanned[u] = true;
  }

  return spanning_cost;
}

int main(){
  int N, M; cin >> N >> M;
  
  rep(i, 0, M){
    int u, v, c; cin >> u >> v >> c;
    E[u].push_back(v);
    E[v].push_back(u);
    W[{u, v}] = W[{v, u}] = c;
  }

  cout << Kruskal() << endl;
  return 0;
}