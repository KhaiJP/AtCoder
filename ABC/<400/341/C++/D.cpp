#include<iostream>
#include<numeric>
using namespace std;
using ll = int64_t;

ll N, M, K, LCM;

bool is_ok(ll x){
  return x / N + x / M - 2*(x / LCM) >= K;
}

int main(){
  cin >> N >> M >> K;
  LCM = N * M / gcd(N, M);

  ll ok = 2e18, ng = 0;
  while(abs(ok - ng) > 1){
    ll mid = (ok + ng) / 2;
    if(is_ok(mid)) ok = mid;
    else           ng = mid;
  }

  cout << ok << endl;
  return 0;
}