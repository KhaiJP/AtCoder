#include<iostream>
#include<vector>
#include<unordered_map>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using Edges = unordered_map<int, vector<int>>;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define yes "Yes"
#define noo "No"

int main(){
  int N, M; cin >> N >> M;
  if(M != N-1){
    cout << noo << endl;
    return 0;
  }
  // set Edges
  Edges E;
  // to check if the graph is connected;
  dsu uf(N);
  rep(i,0,M){
    int u, v; cin >> u >> v;
    --u, --v;
    E[u].push_back(v);
    E[v].push_back(u);
    uf.merge(u,v);
  }

  // number of node which have only 1 adjacency node
  int e1 = 0;
  rep(u,0,N){
    // path graph is a connected graph with 2 nodes which have only 1 adjacency node.
    if(E[u].size() == 0 || E[u].size() > 2 || !uf.same(0,u)){
      cout << noo << endl;
      return 0;
    }
    if(E[u].size() == 1) ++e1;
  }
  
  cout << (e1 == 2 ? yes : noo) << endl;
  return 0;
}