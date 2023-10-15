#include<iostream>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

ll N, Q, A[100010];

int main(){
  cin >> N >> Q;
  rep(i, 1, N+1) cin >> A[i]; A[N+1] = 1e18+1e6;
  N += 2;
  
  while(Q--){
    ll K; cin >> K;
    ll l = 0, r = N;
    while(l+1 < r){
      ll mid = (l + r) / 2;
      if(A[mid] < K + mid) l = mid;
      else                 r = mid;
    }
    cout << K + l << endl;
  }
  return 0;
}