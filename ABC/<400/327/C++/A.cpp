#include<iostream>
using namespace std;

int main(){
  int N; cin >> N;
  string S; cin >> S;
  for(int i = 0; i < N-1; ++i){
    bool is_ab = S[i]=='a' && S[i+1]=='b';
    bool is_ba = S[i]=='b' && S[i+1]=='a';
    if(is_ab || is_ba){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}