#include<iostream>
using namespace std;


bool isChoku(string s){
  int n = s.size();
  s += 'x';
  for(int i = 0; i < n; ++i){
    if(s[i] == 'c'){
      ++i;
      if(s[i] == 'h') continue;
      return false;
    }
    if(s[i] == 'o') continue;
    if(s[i] == 'k') continue;
    if(s[i] == 'u') continue;

    return false;
  }

  return true;
}


int main(){
  string X; cin >> X;
  cout << (isChoku(X) ? "YES" : "NO") << endl;
  return 0;
}
