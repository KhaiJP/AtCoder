#include<iostream>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  int N, Q; cin >> N >> Q;

  dsu uf(N);
  while(Q){
    int t, u, v; cin >> t >> u >> v;
    if(t) cout << (uf.same(u, v) ? 1 : 0) << '\n';
    else  uf.merge(u, v);
    --Q;
  }

  cout << endl;
  return 0;
}