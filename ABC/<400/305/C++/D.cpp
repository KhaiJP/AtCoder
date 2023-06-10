#include<iostream>
#include<algorithm>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int A[200010], pfx[200010];

int main(){
  int N; cin >> N;
  rep(i, 0, N) cin >> A[i];
  rep(i, 1, N+1){
    if(i%2 == 0) pfx[i] = pfx[i-1] + A[i] - A[i-1];
    else         pfx[i] = pfx[i-1];
  }

  int Q; cin >> Q;
  while(Q--){
    int l, r; cin >> l >> r;
    auto dl = lower_bound(A, A+N, l) - A;
    auto dr = lower_bound(A, A+N, r) - A;

    int t = pfx[dr] - pfx[dl];
    if(dl%2 == 0) t += A[dl] - l;
    if(dr%2 == 0) t -= A[dr] - r;
    
    cout << t << endl;
  }
  return 0;
}