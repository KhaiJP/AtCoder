#include<iostream>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

ll A[200010], s, n1, n2, m1, m2;

int main(){
  ll N; cin >> N;
  rep(i, 0, N){ cin >> A[i]; s += A[i]; }
  ll m1 = s / N,    m2 = s / N + 1;

  rep(i, 0, N){
    if(abs(A[i] - m1) < abs(A[i] - m2)) n1 += abs(A[i] - m1);
    else                                n2 += abs(A[i] - m2); 
  }
  cout << max(n1, n2) << endl;
  return 0;
}