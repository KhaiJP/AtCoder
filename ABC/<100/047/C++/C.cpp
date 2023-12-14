#include<iostream>
using namespace std;

int main(){
  string S; cin >> S;
  char me = S[0];
  int answer = 0;
  for(char c : S){
    answer += me != c;
    me = c;
  }
  cout << answer << endl;
  return 0;
}