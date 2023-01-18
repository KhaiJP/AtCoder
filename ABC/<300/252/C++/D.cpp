#include<iostream>
#include<map>
using namespace std;
typedef int64_t ll;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define fore(a, v) for(auto a : v)

int main(){
  ll N; cin >> N;
  map<ll, ll> cnt;
  rep(i,0,N){
    ll A; cin >> A;
    ++cnt[A];
  }
  ll answer = N*(N-1)*(N-2)/6;
  ll two_types = 0;
  ll one_type = 0;
  fore(p, cnt){
    two_types += (N-p.second) * p.second * (p.second-1) /2;
    one_type  += p.second * (p.second-1) * (p.second-2) /6;
  }
  cout << answer - (one_type + two_types) << endl;
  return 0;
}