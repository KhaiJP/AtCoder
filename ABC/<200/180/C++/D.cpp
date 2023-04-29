#include<iostream>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

int main(){
  ll X, Y, A, B; cin >> X >> Y >> A >> B;
  ll exp = 0;

  while( (double)(A) * X < 1e18 && A * X < Y && A * X <= X + B ){
    X *= A;
    ++exp;
  }

  cout << exp + (Y-1 - X) / B << endl;
  return 0;
}