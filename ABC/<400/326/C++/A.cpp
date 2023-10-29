#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  int X, Y; cin >> X >> Y;
  if(X+2 < Y || X > Y+3) cout << "No" << endl;
  else                   cout << "Yes" << endl;
  return 0;
}