#include<iostream>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

ll op(ll a, ll b){
  return max(a, b);
}

ll e(){
  return -1;
}

ll target;
bool f(ll x){
  return x < target;
}

int main(){
  ll N, Q; cin >> N >> Q;

  segtree<ll, op, e> seg(N);
  rep(i, 0, N){
    ll a; cin >> a;
    seg.set(i, a);
  }

  while(Q){
    ll T, X, V; cin >> T >> X >> V; --X;

    if(T == 1) seg.set(X, V);
    if(T == 2) cout << seg.prod(X, V) << '\n';
    if(T == 3){
      target = V;
      cout << seg.max_right(X, f) + 1 << '\n';
    }

    --Q;
  }

  cout << endl;
  return 0;
}