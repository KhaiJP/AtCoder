#include<iostream>
using namespace std;
using ll = int64_t;

int main(){
  ll X; cin >> X;
  ll d = X < 0 && X%10 != 0 ? 1 : 0;
  X /= 10;
  cout << X-d << endl;
  return 0;
}