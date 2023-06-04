#include<iostream>
#include<map>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

ll p[200010], q[200010], a[200010], b[200010];

int main(){
  ll W, H; cin >> W >> H;
  ll N; cin >> N; rep(i, 0, N) cin >> p[i] >> q[i];

  ll A; cin >> A; rep(i, 1, A+1) cin >> a[i];
  ll B; cin >> B; rep(i, 1, B+1) cin >> b[i];
  a[A+1] = W, b[B+1] = H;

  map<pair<ll, ll>, ll> mp;
  rep(i, 0, N){
    ll x = *lower_bound(a, a+A+2, p[i]);
    ll y = *lower_bound(b, b+B+2, q[i]);
    ++mp[{x, y}];
  }

  ll M = 0;
  for(auto p : mp) M = max(M, p.second);
  
  ll m = N;
  if(mp.size() == (A+1) * (B+1))for(auto p : mp) m = min(m, p.second);
  else m = 0;

  cout << m << ' ' << M << endl;
  return 0;
}