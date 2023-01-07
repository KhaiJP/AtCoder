#include<iostream>
#include<set>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, s, t) for (int i = (s); i < (t); ++i)

int main(){
  int N, M; cin >> N >> M;
  dsu uf(N);
  rep(i,0,M){
    int u, v; cin >> u >> v;
    uf.merge(u-1,v-1);
  }
  set<int> s; rep(i,0,N) s.insert(uf.leader(i));
  cout << s.size() << endl;
  return 0;
}