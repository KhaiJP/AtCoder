#include<iostream>
#include<algorithm>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

pair<pair<ll, ll>, ll> P[200010];

bool f(pair<pair<ll, ll>, ll> p1, pair<pair<ll, ll>, ll> p2){
  pair<ll, ll> AB1 = p1.first, AB2 = p2.first;
  ll id1 = p1.second, id2=p2.second;
  ll A1 = AB1.first, B1 = AB1.second;
  ll A2 = AB2.first, B2 = AB2.second;

  if(A1 * (A2+B2) > A2 *(A1+B1)) return true;
  if(A1 * (A2+B2) < A2 *(A1+B1)) return false;
  else return id1 < id2;
}

int main(){
  ll N; cin >> N;
  rep(i, 0, N){
    ll A, B; cin >> A >> B;
    P[i] = {{A,B}, i+1};
  }

  sort(P, P+N, f);
  
  rep(i, 0, N) cout << P[i].second << ' ';
  cout << endl;
  return 0;
}