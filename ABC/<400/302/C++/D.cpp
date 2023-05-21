#include<iostream>
#include<algorithm>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

ll A[200010], B[200010];

int main(){
  ll N, M, D; cin >> N >> M >> D;
  rep(i, 0, N) cin >> A[i];
  rep(j, 0, M) cin >> B[j];
  sort(A, A+N), sort(B, B+M);

  ll answer = -1;
  // brute-force wrt A
  rep(i, 0, N){
    ll &a = A[i];

    // binary-search wrt B
    ll l = 0, r = M;
    while(l+1 < r){
      ll mid = (l + r) / 2;
      ll &b = B[mid];
      // "if b <= a + D" <- this sentence would result overflow
      if(b - a <= D) l = mid;
      else r = mid; 
    }
    // "if b >= a - D && b <= a + D" <- the latter expression would result overflow
    if( B[l] >= a - D  && B[l] - a <= D) answer = max(answer, a + B[l]);
  }

  cout << answer << endl;
  return 0;
}