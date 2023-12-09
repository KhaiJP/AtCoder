#include<iostream>
#include<vector>
#include<atcoder/all>
using namespace std;
using ll = int64_t;
using UF = atcoder::dsu;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

ll C[200010], answer;
int N, X[200010];
bool visited[200010];

template <typename T>
vector<T> find_loop_of_functional_graph(vector<T> &V){
  // V is the vetices set of a directed Graph G(G is not necessarily explicitly defined)
  // Edges info E and bool array visited[] must be defined as the global variable
  T Vsize = V.size();
  T u = V[0];

  while(true){
    if(visited[u]){
      T v = u;
      vector<T> loop;
      do{
        loop.push_back(v);
        v = X[v];
      }while(v != u);
      return loop;
    }
    visited[u] = true;
    // E is X in this problem
    u = X[u];
  }
}

int main(){
  cin >> N;
  UF uf(N);
  rep(i, 0, N) cin >> X[i];
  rep(i, 0, N) cin >> C[i];
  rep(i, 0, N){
    --X[i];
    uf.merge(i, X[i]);
  }

  for(auto G : uf.groups()){
    vector<int> V = find_loop_of_functional_graph(G);
    ll m = 1e18;
    for(auto u : V) m = min(m, C[u]);
    answer += m;
  }

  cout << answer << endl;
  return 0;
}