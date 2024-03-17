#include<iostream>
using namespace std;

int main(){
  string S; cin >> S;

  bool f = S.front() == '<' && S.back() == '>';

  int N = S.size();
  for(int i = 1; i < N-1; ++i){
    f = f && S[i] == '=';
  }

  cout << (f ? "Yes" : "No") << endl;
  return 0;
}