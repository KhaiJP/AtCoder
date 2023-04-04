#include<iostream>
#include<algorithm>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

// sort and greedy
int A[100010], B[100010];

int main(){
  int N; cin >> N;
  
  rep(i, 0, N) cin >> A[i];
  sort(A, A+N);
  rep(i, 0, N) cin >> B[i];
  sort(B, B+N);

  int64_t answer = 0;
  rep(i, 0, N) answer += abs(A[i] - B[i]);

  cout << answer << endl;
  return 0;
}