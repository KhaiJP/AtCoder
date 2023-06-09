#include<iostream>
using namespace std;

int main(){
  int A, B, W; cin >> A >> B >> W;
  W *= 1000;

  int b = (W + B - 1) / B;
  if(b * A > W) cout << "UNSATISFIABLE" << endl;
  else cout << b << ' ' << W/A << endl;
  return 0;
}