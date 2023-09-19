#include<iostream>
using namespace std;

int N, answer;

int main(){
  string S, T; cin >> S >> T;
  N = S.size();
  for(int i = 0; i < N; ++i) answer += S[i]!=T[i];
  cout << answer << endl;
  return 0;
}