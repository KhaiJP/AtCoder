#include<iostream>
#include<map>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s);  i < (t); ++i)

map<ll, ll> cnt, pfx;
ll N, A[200010], B[200010], S;

int main(){
  cin >> N;
  rep(i, 0, N) cin >> A[i];
  rep(i, 0, N) ++cnt[A[i]];
  for(auto p : m){
    ll a = p.first, n = p.second;
    S += a*n;
    pfx[a] = S; 
  }

  rep(i, 0, N) cout << S - pfx[A[i]] << ' '; cout << endl;
  return 0;
}