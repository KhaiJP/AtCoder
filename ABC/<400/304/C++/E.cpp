#include<iostream>
#include<set>
#include<utility>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  int N, M; cin >> N >> M;
  
  dsu uf(N);
  rep(i, 0, M){
    int u, v; cin >> u >> v; --u, --v;
    uf.merge(u, v);
  }

  set<pair<int, int>> S;
  int K; cin >> K;
  bool allno = false;
  rep(i, 0, K){
    int x, y; cin >> x >> y; --x, --y;
    x = uf.leader(x), y = uf.leader(y);
    if(x > y) swap(x, y);
    S.insert({x, y});
    allno = allno || x == y;
  }

  int Q; cin >> Q;

  rep(i, 0, Q){
    if(allno){
      cout << "No" << endl;
      continue;
    }
    
    int p, q; cin >> p >> q; --p, --q;
    p = uf.leader(p), q = uf.leader(q);
    if(p > q) swap(p, q);
    cout << (S.count({p, q}) == 1 ? "No" : "Yes") << endl;
  }

  return 0;
}