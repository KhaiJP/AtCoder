#include<iostream>
#include<algorithm>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

ll op(ll, ll){ return 0; }
ll e(){ return 0; }
ll mapping(ll l, ll r){ return l + r; }
ll composition(ll l, ll r){ return l + r; }
ll id(){ return 0; }

ll N, M;

int main(){
  cin >> N >> M;
  vector<ll> A(N);
  rep(i, 0, N) cin >> A[i];

  lazy_segtree<ll, op, e, ll, mapping, composition, id> seg(A);
  rep(i, 0, M){
    ll b_idx; cin >> b_idx;
    ll nBalls = seg.get(b_idx);
    seg.set(b_idx, 0);

    ll d_max = nBalls % N;
    ll nRounds = nBalls / N;
    
    seg.apply(0, N, nRounds);
    if(b_idx + d_max < N){
      seg.apply(b_idx+1, b_idx+d_max+1, 1);
    }
    else{
      seg.apply(b_idx+1, N, 1);
      d_max = b_idx + d_max - N;
      seg.apply(0, d_max+1, 1);
    }
  }

  rep(i, 0, N) cout << seg.get(i) << ' '; cout << endl;
  return 0;
}