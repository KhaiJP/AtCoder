#include<iostream>
#include<algorithm>
#include<atcoder/all>
using namespace std;
using ll = int64_t;
using UF = atcoder::dsu;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

ll N, answer;
tuple<ll, ll, ll> E[100010];

int main(){
  cin >> N;
  UF uf(N);
  rep(i, 0, N-1){
    ll u, v, w; cin >> u >> v >> w;
    --u, --v;
    E[i] = {w, u, v};
  }sort(E, E+N-1);

  rep(i, 0, N-1){
    ll w, u, v;
    tie(w, u, v) = E[i];
    answer += w * uf.size(u) * uf.size(v);
    uf.merge(u, v);
  }

  cout << answer << endl;
  return 0;
}