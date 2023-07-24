#include<iostream>
using namespace std;
using ll = int64_t;

ll f(ll x){ return (x&1 ? 0 : x) ^ (((x+1)/2)&1);}

int main(){
  ll A, B; cin >> A >> B;
  cout << (f(B) ^ f(A-1)) << endl;
  return 0;
}