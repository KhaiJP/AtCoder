#include<iostream>
#include<atcoder/all>
using namespace std;
using ll = int64_t;
using UF = atcoder::dsu;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

ll N, M, answer = 1, mod = 998244353, deg[200010];

int main(){
  cin >> N >> M;
  UF uf(N);
  rep(i, 0, M){
    int u, v; cin >> u >> v; --u, --v;
    uf.merge(u, v);
    ++deg[u], ++deg[v];
  }

  for(auto g : uf.groups()){
    int tot_deg = 0;
    for(auto u : g) tot_deg += deg[u];
    if((int)g.size() * 2 == tot_deg){
      answer = (answer * 2) % mod;
    }else{
      answer = 0;
    }
  }
  cout << answer << endl;
  return 0;
}