#include<iostream>
#include<algorithm>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int A[200010];

int main(){
  int N, K, X; cin >> N >> K >> X;
  
  rep(i, 0, N){
    int a; cin >> a;
    int n = min(a/X, K);
    A[i] = a - n*X;
    K -= n;
  }sort(A, A+N);

  ll answer = 0;
  rep(i, 1, N+1){
    answer += (K > 0 ? 0 : A[N-i]);
    --K;
  }

  cout << answer << endl;
  return 0;
}