#include<iostream>
using namespace std;

int main(){
  int64_t a, b, c; cin >> a >> b >> c;

  if( c - (a + b) <= 0 ){
    cout << "No" << endl;
    return 0;
  }

  cout << (4*a*b < (c - (a+b)) * (c - (a+b)) ? "Yes" : "No") << endl;
  return 0;
}