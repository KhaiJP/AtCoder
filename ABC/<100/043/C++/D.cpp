#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  string s; cin >> s;
  s += '?';
  rep(i, 0, s.size()-2){
    if(s[i+1] == s[i]){
      cout << i+1 << ' ' << i+2 << endl;
      return 0;
    }
    if(s[i+2] == s[i]){
      cout << i+1 << ' ' << i+3 << endl;
      return 0;
    }
  }
  cout << -1 << ' ' << -1 << endl;
  return 0;
}