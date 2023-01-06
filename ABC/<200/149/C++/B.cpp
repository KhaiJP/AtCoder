#include<iostream>
using namespace std;

int main(){
  int64_t A, B, K; cin >> A >> B >>K;
  B = A <= K ? max(B-(K-A), (int64_t)0) : B;
  A = max(A-K, (int64_t)0);
  cout << A << ' ' << B << endl;
  return 0;
}