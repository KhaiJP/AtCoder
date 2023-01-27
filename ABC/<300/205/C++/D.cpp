#include<iostream>
#include<algorithm>
using namespace std;
typedef int64_t ll;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

ll A[100000], good[100100];

int main(){
  ll N, Q; cin >> N >> Q;
  
  rep(i,0,N) cin >> A[i];
  sort(A, A+N);

  rep(i,0,N) good[i] = A[i] - (i+1);

  rep(q, 0, Q){
    ll K; cin >> K;
    ll *p = lower_bound(good, good+N, K);
    ll  d = distance(good, p);
    
    if(d == N) cout << A[N-1] + ( K - good[N-1] ) << '\n';
    else cout << A[d] -( good[d] - K + 1) << '\n';
  }
  return 0;
}
