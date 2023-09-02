#include<iostream>
#include<atcoder/all>
#include<set>
using namespace std;
using UF = atcoder::dsu;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  int N, M; cin >> N >> M;
  UF uf(N + 1);
  rep(i, 0, M){
    int u, v; cin >> u >> v;
    uf.merge(u, v);
  }

  int K; cin >> K;
  set<pair<int, int>> lXY;
  rep(i, 0, K){
    int x, y; cin >> x >> y;
    int lx = uf.leader(x), ly = uf.leader(y);
    if(lx > ly) swap(lx, ly);
    lXY.insert({uf.leader(lx), uf.leader(ly)});
  }
  
  int Q; cin >> Q;
  while(Q--){
    int p, q; cin >> p >> q;
    int lp = uf.leader(p), lq = uf.leader(q);
    if(lp > lq) swap(lp, lq);
    cout << (lXY.count({uf.leader(lp), uf.leader(lq)}) == 1 ? "No" : "Yes") << endl;
  }

  return 0;
}