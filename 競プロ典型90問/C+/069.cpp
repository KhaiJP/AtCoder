#include<iostream>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

ll const MOD = 1e9 + 7;

ll powmod(ll a, ll n){
  if(n == 0) return 1;
  ll ret = 1;
  while(n){
    if(n & 1) ret = ret * a % MOD;
    a = a * a % MOD;
    n /= 2;
  }
  return ret;
}


int main(){
  ll N, K; cin >> N >> K;
  if(N == 1){
    cout << K << endl;
    return 0;
  }

  ll answer = K * (K-1) % MOD;
  answer = answer * powmod(K-2, N-2) % MOD;
  cout << answer << endl;
  return 0;
}