#include<iostream>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int indeg_of[200010];

int main(){
  int N, M; cin >> N >> M;
  if(M != N-1){
    cout << "No" << endl;
    return 0;
  }

  dsu uf(N);
  rep(i, 0, M){
    int u, v; cin >> u >> v; --u, --v;
    uf.merge(u, v);
    ++indeg_of[u], ++indeg_of[v];
    if(indeg_of[u] == 3 || indeg_of[v] == 3){
      cout << "No" << endl;
      return 0;
    }
  }

  int deg_is_1 = 0;
  rep(u, 0, N) deg_is_1 += indeg_of[u] == 1;
  
  cout << (uf.groups().size() == 1  &&  deg_is_1 == 2 ? "Yes" : "No") << endl;
  return 0;
}