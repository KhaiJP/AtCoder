#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using ll = int64_t;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

set<int> E[200010];
bool spanned[200010];
map<pair<int, int>, int> W;
dsu uf(200010);

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

  ll total = 0;
  rep(i, 0, M){
    int A, B, C; cin >> A >> B >> C;
    --A, --B;
    C = max(C, 0);
    if(A != B){
      E[A].insert(B);
      E[B].insert(A);
      if(W.count({A, B}) == 0) W[{A, B}] = W[{B, A}] = C;
      else W[{A, B}] = W[{B, A}] = min(W[{A, B}], C);
    }
    total += C;
  }

  cout << total - Kruskal() << endl;
  return 0;
}
