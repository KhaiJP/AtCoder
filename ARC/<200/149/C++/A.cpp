#include<iostream>
#include<queue>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

priority_queue<pair<ll, ll>> q;
ll N, M;

void pushing(ll i){
  ll ord = 0;
  ll m = i%M;
  while(ord < N){
    ++ord;
    if(m == 0) q.push({ord, i});
    m = (10*m + i) % M;
  }
}

int main(){
  cin >> N >> M;
  rep(i, 1, 10) pushing(i);

  if(q.empty()){
    cout << -1 << endl;
    return 0;
  }

  ll n = q.top().first, d = q.top().second;
  rep(i, 0, n) cout << d;
  cout << endl;
  return 0;
}