#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  rep(i, 0, 26){
    int P; cin >> P; --P;
    cout << (char)('a' + P);
  }
  cout << endl;
  return 0;
}