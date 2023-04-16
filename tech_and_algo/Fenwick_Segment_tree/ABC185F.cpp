#include<iostream>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

ll op(ll a, ll b){
  return a ^ b;
}

ll e(){
  return 0;
}

int main(){
  int N, Q; cin >> N >> Q;
  segtree<ll, op, e> seg(N);

  rep(i, 0, N){
    ll A; cin >> A;
    seg.set(i, A);
  }

  while(Q){
    ll T, X, Y; cin >> T >> X >> Y; 
    --X;

    if(T == 1){
      seg.set(X, seg.get(X) ^ Y);
    }
    if(T == 2){
      cout << seg.prod(X, Y) << '\n';
    }

    --Q;
  }
}