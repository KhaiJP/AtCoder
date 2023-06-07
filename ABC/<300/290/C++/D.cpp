#include<iostream>
#include<numeric>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  int T; cin >> T;
  while(T--){
    ll N, D, K; cin >> N >> D >> K; --K;
    ll A = N/gcd(N, D);
    cout << D * K % N + K / A << '\n';
  }

  cout << endl;
  return 0;
}