#include<iostream>
#include<string>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  string S; cin >> S;
  int N = S.size();
  
  int answer = 0;
  for(char c : S) answer -= c == 'p';
  answer += N/2;

  cout << answer << endl;
  return 0;
}