#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  rep(i, 0, 8)rep(j, 0, 8){
    char c; cin >> c;
    if(c == '*'){
      cout << (char)('a' + j) << 8-i << endl;
      return 0;
    }
  }
}