#include<iostream>
using namespace std;

int main(){
  int R, G; cin >> R >> G;
  // (R+answer)/2 = G  => answer = 2*G - R
  cout << 2*G - R << endl;
  return 0;
}