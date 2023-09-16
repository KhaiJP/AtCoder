#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

string S;
int N, answer;

bool isPalindrome(int s, int t){
  bool flag = true;
  rep(i, 0, t-s) flag = flag && S[s+i] == S[t-i];
  return flag;
}

int main(){
  cin >> S;
  N = S.size();
  
  rep(s, 0, N-1)rep(t, s, N)if(isPalindrome(s, t)){
    answer = max(answer, t - s + 1);
  }
  cout << answer << endl;
  return 0;
}