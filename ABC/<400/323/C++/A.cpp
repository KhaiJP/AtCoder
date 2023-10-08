#include<iostream>
using namespace std;

int main(){
  string S; cin >> S;
  bool flag = true;
  for(int i = 1; i < 16; i += 2) flag = flag && S[i]=='0';
  cout << (flag ? "Yes" : "No") << endl;
  return 0;
}