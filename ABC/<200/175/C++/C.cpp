#include<iostream>
using namespace std;
using ll = int64_t;

int main(){
  ll X, K, D; cin >> X >> K >> D;
  X = abs(X);
  if( X/D >= K ){
    cout << X - K*D << endl;
    return 0;
  }
  else{
    ll q = X/D;
    cout << ( q&1 ^ K&1 ? D - X % D : X % D ) << endl;
    return 0;
  }
}