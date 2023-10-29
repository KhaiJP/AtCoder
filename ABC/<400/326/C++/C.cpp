#include<iostream>
#include<algorithm>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int N, M, A[300010], answer;

int main(){
  cin >> N >> M;
  rep(i, 0, N) cin >> A[i];
  sort(A, A+N);

  rep(i, 0, N){
    int n = lower_bound(A, A+N, A[i]+M) - A;
    answer = max(answer, n - i);
  }

  cout << answer << endl;
  return 0;
}