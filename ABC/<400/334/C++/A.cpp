#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  int B, G; cin >> B >> G;
  cout << (B > G ? "Bat" : "Glove") << endl;
  return 0;
}