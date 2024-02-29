#include<iostream>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

ll N, Q, A[100010];

bool check(ll &m, ll &K){
  return A[m]-m < K;
}

ll my_binary_search(ll K){
  ll ok = 0, ng = N+1;
  while(abs(ok - ng) > 1){
    ll mid = (ok + ng) / 2;
    if(check(mid, K)) ok = mid;
    else              ng = mid;
  }

  return K + ok;
}

int main(){
  cin >> N >> Q;
  rep(i, 1, N+1) cin >> A[i];
  A[N+1] = 1e18 + 1e6;

  while(Q--){
    ll K; cin >> K;
    cout << my_binary_search(K) << endl;
  }

  return 0;
}