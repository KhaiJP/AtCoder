#include<iostream>
#include<algorithm>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define rrep(i, s, t) for(int i = (s); i >= (t); --i)

// pfx[i]; sum( #({ k | C[k] > B[l] }) | l >= i ) here B and C are sorted in increasing order
ll A[100010], B[100010], C[100010], pfx[100010];

int main(){
  ll N; cin >> N;
  rep(i, 0, N) cin >> A[i];
  rep(i, 0, N) cin >> B[i]; 
  rep(i, 0, N) cin >> C[i];
  sort(A, A + N), sort(B, B + N), sort(C, C + N);

  // j = min( { k | C[k] > B[N-1] } ) -> #( { k | C[k] > B[N-1] } ) = N - j
  auto j = upper_bound(C, C + N, B[N-1]) - C;
  pfx[N-1] = N - j;

  rrep(i, N-2, 0){
    auto j = upper_bound(C, C + N, B[i]) - C;
    pfx[i] = pfx[i + 1] + (N - j); 
  }

  ll answer = 0;
  rep(i, 0, N){
    auto ib = upper_bound(B, B + N, A[i]) - B;
    answer += pfx[ib];
  }

  cout << answer << endl;
  return 0;
}