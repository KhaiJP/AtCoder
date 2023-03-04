#include<iostream>
#include<map>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

ll divs[200010];
ll numDivisors(ll n);

int main(){
  ll n; cin >> n;
  rep(i, 1, n) divs[i] = numDivisors(i);
  ll ans = 0;
  rep(i, 1, n) ans += divs[i] * divs[n-i];
  cout << ans;
  return 0;
}

ll numDivisors(ll n){
  map<ll, ll> ref;
  while(n%2 == 0){
    ++ref[2];
    n /= 2;
  }
  for(ll i = 3; i*i <= n; i += 2){
    while(n%i == 0){
      ++ref[i];
      n /= i;
    }
  }
  if(n > 1) ++ref[n];
  ll ret = 1;
  for(auto p : ref) ret *= p.second + 1;
  return ret;
}