#include<iostream>
#include<map>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

int main(){
  ll N, W; cin >> N >> W;

  map<ll, ll> m;
  rep(i, 0, N){
    ll A, B; cin >> A >> B;
    m[-A] += B;
  }

  ll answer = 0;
  for(auto p : m){
    const ll &A = -p.first;
    const ll &B = p.second;
    if(W - B <= 0){ answer += W*A; break; }
    
    answer += B*A;
    W -= B;
  }
  cout << answer << '\n';
  return 0;
}