#include<iostream>
#include<vector>
#include<algorithm>
#include<atcoder/all>
using namespace std;
using ll = int64_t;
using UF = atcoder::dsu;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

ll N, M, K, W[100], answer = 1e18;
pair<ll,ll> p[100];
vector<bool> V;

ll get_weights_sum(){
  ll weights_sum = 0;
  UF uf(N);
  rep(i, 0, M)if(V[i]){
    ll u = p[i].first, v = p[i].second;
    uf.merge(u, v);
    weights_sum += W[i]; 
  }

  return uf.groups().size() == 1 ? weights_sum%K : 1e18;
}

int main(){
  cin >> N >> M >> K;
  rep(i, 0, M){
    ll u, v, w; cin >> u >> v >> w;
    --u, --v, w %= K;
    p[i] = {u, v};
    W[i] = w;
  }

  rep(i, 0, M) V.push_back(true);
  rep(i, 0, M-(N-1)) V[i] = false;

  do{
    answer = min(answer, get_weights_sum());
  }while(next_permutation(V.begin(), V.end()));

  cout << answer << endl;
  return 0;
}