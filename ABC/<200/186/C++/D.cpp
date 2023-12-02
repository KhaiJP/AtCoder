#include<iostream>
#include<algorithm>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

ll N, A[200010], pfx[200010], answer;

int main(){
  cin >> N;
  rep(i, 0, N) cin >> A[i];
  sort(A, A+N, greater<ll>());
  rep(i, 0, N) pfx[i+1] = pfx[i] + A[i];
  rep(i, 0, N) answer += pfx[i] - i*A[i];
  cout << answer << endl;
  return 0;
}