#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int main(){
  string S; cin >> S;
  if(S[0]=='1'){
    cout << "No" << endl;
    return 0;
  }
  vector<bool> lines(7, true);
  if(S[6]=='0') lines[0] = false;
  if(S[3]=='0') lines[1] = false;
  if(S[1]=='0' && S[7]=='0') lines[2] = false;
  if(S[4]=='0') lines[3] = false;
  if(S[2]=='0' && S[8]=='0') lines[4] = false;
  if(S[5]=='0') lines[5] = false;
  if(S[9]=='0') lines[6] = false;
  bool flag = true;
  for(int i = 0; i < 6; ++i){
    for(int j = i+1; j < 7; ++j){
      if(lines[i] && lines[j]){
        for(int k = i+1; k < j; k++){
          if(!lines[k]){
            cout << "Yes" << endl;
            return 0;
          }
        }
      }
    }
  }
  cout << "No" << endl;
  return 0;
}