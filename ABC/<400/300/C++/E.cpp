#include<iostream>
#include<atcoder/all>
#include<map>
#include<queue>
using namespace std;
using ll = int64_t;
using mint = atcoder::modint998244353;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

map<ll, mint> m;

int main(){
  ll N; cin >> N;
  m[1] = 1;
  queue<ll> q; q.push(1);
  
  while(q.size()){
    ll u = q.front(); q.pop();
    rep(n, 2, 7){
	  ll M = u * n;
      if(m.count(M) == 0 && M < N) q.push(M);
      m[M] += m[u] / 5;
    }
  }
  
  cout << m[N].val() << endl;
  return 0;
}
