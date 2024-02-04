#include<iostream>
#include<algorithm>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

ll op(ll , ll ){ return 0; }
ll e(){ return 0; }
ll mapping(ll l, ll r){ return l+r; }
ll composition(ll l, ll r){ return l+r; }
ll id(){ return 0; }

ll N, D, A, answer;
pair<ll, ll> XH[200010];

int main(){
  cin >> N >> D >> A;
  rep(i, 0, N){
    ll x, h; cin >> x >> h;
    XH[i] = {x, h};
  }sort(XH, XH+N);

  vector<ll> X(N), H(N);
  rep(i, 0, N) X[i] = XH[i].first, H[i] = XH[i].second;
  lazy_segtree<ll, op, e, ll, mapping, composition, id> seg(H);

  rep(i, 0, N){
    auto h = seg.get(i);
    if(h <= 0) continue;

    ll n = (h + A - 1) / A;
    auto itr = upper_bound(X.begin(), X.end(), X[i]+2*D);
    ll j = distance(X.begin(), itr);
    seg.apply(i, j, -n*A);
    answer += n;
  }

  cout << answer << endl;
  return 0;
}