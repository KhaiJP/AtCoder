#include<iostream>
using namespace std;
typedef int64_t ll;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

int main(){
  ll N; cin >> N;
  ll answer = 0;
  rep(i, 1, N+1){
    // find q st i = s*q and s is maximum squared
    // then i * (q*l^2) = s*q * (q*l^2) = s^2*q^2*l^2 is squared 
    ll q = i;
    for(ll d = 2; d*d <= q; ++d)while(q%(d*d) == 0) q /= d*d;
    for(ll d = 1; q*d*d <= N; ++d) ++answer;
  }
  cout << answer << endl;
  return 0;
}