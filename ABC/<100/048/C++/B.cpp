#include<iostream>
using namespace std;
using ll = int64_t;

ll f(ll n, ll x){
  return (n == -1 ? 0 : n/x + 1);
}

int main(){
  ll a, b, x; cin >> a >> b >> x;
  cout << f(b, x) - f(a-1, x) << endl;
  return 0;
}