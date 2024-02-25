#include<iostream>
using namespace std;

int main(){
  string S; cin >> S;
  if(S[0] == S[1]){
    for(int i = 2; i < S.size(); ++i){
      if(S[i] != S[0]){
        cout << i+1 << endl;
        return 0;
      }
    }
  }else{
    cout << (S[0] == S[2] ? 2 : 1) << endl;
    return 0;
  }
}