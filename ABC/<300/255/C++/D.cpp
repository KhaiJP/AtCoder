#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef int64_t ll;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  ll N, Q; cin >> N >> Q;
  vector<ll> A(N); rep(i,0,N) cin >> A[i];
  sort(A.begin(), A.end());
  vector<ll> pfx(N+1,0); rep(i,1,N+1) pfx[i] = pfx[i-1] + A[i-1];

  rep(q,0,Q){
    ll X; cin >> X;
    auto itr = lower_bound(A.begin(), A.end(), X);
    ll index = distance(A.begin(), itr);
    cout << (2*index - N)*X + pfx[N] - 2*pfx[index] << '\n';
  }
  return 0;
}