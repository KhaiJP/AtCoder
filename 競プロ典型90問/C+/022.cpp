#include<iostream>
using namespace std;
using ll = int64_t;

ll gcd(ll a, ll b){
  if( b == 0 ) return a;
  return gcd(b, a % b);
}

int main(){
  ll A, B, C; cin >> A >> B >> C;
  ll d = gcd(A, gcd(B, C));
  cout << (A/d - 1) + (B/d - 1) + (C/d - 1) << endl;
  return 0;
}