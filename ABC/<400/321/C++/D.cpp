#include<iostream>
#include<algorithm>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

ll N, M, P, answer, A[200010], B[200010], pfxB[200010];

int main(){
  cin >> N >> M >> P;
  rep(i, 0, N) cin >> A[i]; sort(A, A+N);
  rep(i, 0, M) cin >> B[i]; sort(B, B+M);
  rep(i, 0, M) pfxB[i+1] = pfxB[i] + B[i];

  rep(i, 0, N){
    ll j = lower_bound(B, B+M, P-A[i]) - B;
    answer += (j * A[i] + pfxB[j]) + (M-j) * P;
  }

  cout << answer << endl;
  return 0;
}