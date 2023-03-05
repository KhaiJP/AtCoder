#include<iostream>
#include<string>
using namespace std;

int main(){
  string S; cin >> S;
  int i = 1;
  while(S[S.size()-i] == 'a')++i;
  --i;
  
  int j = 0;
  while(S[j] == 'a')++j;
  for(int k = 0; k < i-j; k++) S.pop_back();
  
  for(int i = 0; i < S.size(); ++i){
    if(S[i] != S[S.size()-i-1]){
      cout << "No" << endl;
      return 0;
    }
  }
  
  cout << "Yes" << endl;
  return 0;
}