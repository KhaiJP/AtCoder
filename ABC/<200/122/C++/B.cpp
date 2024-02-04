#include<iostream>
using namespace std;

int main(){
  string S; cin >> S;
  S += 'X';
  int N = S.size();
  int k = 0, answer = 0;

  for(int i = 0; i < N; ++i){
    char c = S[i];
    if(c == 'A' || c == 'T' || c == 'G' || c == 'C') continue;
    answer = max(answer, i-k);
    k = i+1;
  }
  cout << answer << endl;
  return 0;
}