#include<iostream>
#include<string>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  string S; cin >> S;
  
  rep(i,0,S.size()){
    if(S[i] == '0') S[i] = '1';
    else if(S[i] == '1') S[i] = '0';
  }

  cout << S << endl;
  return 0;
}