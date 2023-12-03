#include<iostream>
#include<set>
#include<map>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

ll N, answer;
map<ll, ll> R, C;
map<pair<ll, ll>, ll> m;
set<pair<ll, ll>> Rn, Cn;

int main(){
  cin >> N;
  rep(i, 0, N){
    ll r, c, x; cin >> r >> c >> x;
    R[r] += x;
    C[c] += x;    
    m[{r,c}] = x;
  }
  
  for(auto p : R) Rn.insert({-p.second, p.first});
  for(auto p : C) Cn.insert({-p.second, p.first});

  for(auto p : Rn)for(auto q : Cn){
    ll x = -p.first,  y = -q.first;
    ll r = p.second, c = q.second;
    answer = max(answer, x + y - m[{r, c}]);
    if(m[{r, c}] == 0) break;
  }

  cout << answer << endl;
  return 0;
}