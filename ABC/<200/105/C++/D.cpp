#include<iostream>
#include<map>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

ll N, M, A[100010], pfx[100010], answer;
map<ll, ll> m;

int main(){
  cin >> N >> M;
  rep(i, 0, N) cin >> A[i];

  rep(i, 0, N) pfx[i+1] = pfx[i] + A[i];
  rep(i, 0, N+1) ++m[pfx[i]%M];

  for(auto p : m){
    ll K = p.second;
    answer += K * (K-1) / 2;
  }

  cout << answer << endl;
  return 0;
}