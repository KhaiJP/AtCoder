#include<iostream>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using ll = int64_t;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  int N, Q; cin >> N >> Q;
  fenwick_tree<ll> bit(N);
  
  rep(i, 0, N){
    ll a; cin >> a;
    bit.add(i, a);
  }

  while(Q){
    ll e, l, r; cin >> e >> l >> r;
    if(e) cout << bit.sum(l, r) << '\n';
    else bit.add(l, r);

    --Q;
  }

  cout << endl;
  return 0;
}