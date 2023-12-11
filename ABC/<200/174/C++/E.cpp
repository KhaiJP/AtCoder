#include<iostream>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

ll N, K, A[200010], M;

bool is_ok(int m){
  ll k = 0;
  rep(i, 0, N) k += (A[i] + m - 1) / m - 1;
  return k <= K;
}

int main(){
  cin >> N >> K;
  rep(i, 0, N) cin >> A[i];
  rep(i, 0, N) M = max(M, A[i]);
  
  ll  ok = M, ng = 0;
  while(abs(ok-ng) > 1){
    ll mid = (ok + ng) / 2;
    if(is_ok(mid)) ok = mid;
    else           ng = mid;
  }

  cout << ok << endl;
  return 0;
}