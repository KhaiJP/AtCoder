#include<iostream>
#include<algorithm>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

ll A[100010];

int main(){
  ll N; cin >> N;
  rep(i, 0, N) cin >> A[i];
  sort(A, A+N);

  if(N & 1){
    ll m1 = A[N/2 - 1], m2 = A[N/2], m3 = A[N/2 + 1];
    ll mid = 0; rep(i, 0, N) mid += abs(A[i] - m2);
    cout << 2 * mid - min(m2-m1, m3-m2) << endl;
  }else{
    ll m1 = A[N/2 - 1], m2 = A[N/2];
    ll mid = 0; rep(i, 0, N) mid += abs(A[i] - m1);
    cout << 2 * mid - (m2 - m1) << endl;
  }

  return 0;
}
