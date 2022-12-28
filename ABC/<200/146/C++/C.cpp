#include<iostream>
using namespace std;

int64_t pw(int64_t b, int p);
/*
  Let us consider a sequence f(1|A,B), f(2|A,B), ... , f(1e9|A,B), where f(n|A,B) = A*n + B*d(n).
  Not only this sequence is monotonically increasing, each subsequence, 10^(i-1):10^i-2 .|> f, is arithmetic with gap A.
  Only the gap between 10^i-1 |> f and 10^i |> f is A+B.
  if X is within 10^(i-1):10^i-2 .|> f, 10^(i-1) + (X - f(10^(i-1)))/A is the maximum integer, 
  and if X is within  10^i-2:10^i-1 .|> f, 10^(i-1) + (X - f(10^(i-1)) - B)/A is the maximum integer
*/
int main(){
  int64_t A, B, X; cin >> A >> B >> X;
  if(X < A+B){
    cout << 0 << endl;
    return 0;
  }

  const int64_t TEN=10;
  for(int i=1; i<=9; ++i){
    if(X >= pw(TEN,i)*A + (i+1)*B) continue;

    X -= pw(TEN, i-1)*A + i*B;
    if((pw(TEN,i) -pw(TEN,i-1) - 1)*A + B <= X) X -= B;
    
    cout << pw(TEN, i-1) + X/A << endl;
    return 0;
  }
  cout << 1000000000 << endl;
  return 0;
}

// b: base, p: power. returns b^p
int64_t pw(int64_t b, int p){
  int64_t ans=1;
  for(int i=1; i<=p; ++i)ans *= b;
  return ans;
}