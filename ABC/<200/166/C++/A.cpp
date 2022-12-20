#include<iostream>
#include<string>
using namespace std;
int main(){
  string S; cin >> S;
  if(S[1]=='R') S[1]='B';
  else if(S[1]=='B') S[1]='R';
  cout << S << endl;
  return 0;
}