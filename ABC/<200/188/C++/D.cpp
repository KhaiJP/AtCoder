#include<iostream>
#include<map>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

ll N, C, answer, cost, pre;
map<ll, ll> m;

int main(){
  cin >> N >> C;
  rep(i, 0, N){
    ll a, b, c; cin >> a >> b >> c;
    m[a] += c;
    m[b+1] -= c;
  }

  pre = 1;
  for(auto p : m){
    answer += min(cost, C) * (p.first - pre);
    cost   += p.second;
    pre     = p.first; 
  }

  cout << answer << endl;
  return 0;
}