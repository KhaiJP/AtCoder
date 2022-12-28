#include<iostream>
using namespace std;

int main(){
  int A, D; cin >> A >> D;
  A <= D ? A += 1 : D += 1;
  cout << A*D << endl;
  return 0;
}