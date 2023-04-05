#include<iostream>
using namespace std;
using ull = uint64_t;

ull LARGE = 1000000000000000000;

ull gcd(ull a, ull b){
  if(b == 0) return a;
  return gcd(b, a % b);
}

int main(){
  ull A, B; cin >> A >> B;
  
  ull d = gcd(A, B);
  B = B/d;
  if(B > LARGE/A) cout << "Large" << endl;
  else cout << A*B << endl;
  return 0;
}