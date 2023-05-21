#include<iostream>
#include<set>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)


set<int> E[300010]; 

int main(){
  int N, Q; cin >> N >> Q;

  // number of isolated nodes
  int n_isolated = N;
  while(Q){
    int e; cin >> e;

    if(e == 1){
      int u, v; cin >> u >> v; --u, --v;

      if(E[u].size() == 0) --n_isolated;
      if(E[v].size() == 0) --n_isolated;

      E[u].insert(v), E[v].insert(u);
    }


    if(e == 2){
      int u; cin >> u; --u;

      for(auto v : E[u]){
        E[v].erase(u);
        if(E[v].size() == 0) ++n_isolated;
      }

      // in the case node u is already isolated, check u's degree
      if(E[u].size() != 0) ++n_isolated;
      E[u].clear();
    }

    cout << n_isolated << '\n';
    --Q;
  }

  cout << endl;
  return 0;
}