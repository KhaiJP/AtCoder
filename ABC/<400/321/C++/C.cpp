#include<iostream>
#include<queue>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

int main(){
  ll K; cin >> K;
  
  queue<ll> q;
  rep(i, 1, 10) q.push(i);

  ll answer;
  while(K--){
    ll u = q.front(); q.pop();
    answer = u;
    ll m = u % 10;
    rep(i, 0, m) q.push(10 * u + i);
  }

  cout << answer << endl;
  return 0;
}