#include<iostream>
using namespace std;

int main(){
  int x, y; cin >> x >> y;
  cout << (x == y ? x : 3 - (x + y)) << endl;
  return 0;
}