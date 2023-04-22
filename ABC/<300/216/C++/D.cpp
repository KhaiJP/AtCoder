#include<iostream>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)


int main(){
  int N, M; cin >> N >> M;
  scc_graph scc(N);

  rep(i, 0, M){
    int k, pre = -1; cin >> k;
    rep(j, 0, k){
      int a; cin >> a; --a;
      if(pre != -1) scc.add_edge(pre, a);
      if(pre == a){
        cout << "No" << endl;
        return 0;
      }
      pre = a;
    }
  }

  auto v = scc.scc();
  cout << ( v.size() == N ? "Yes" : "No") << endl;
  return 0;
}