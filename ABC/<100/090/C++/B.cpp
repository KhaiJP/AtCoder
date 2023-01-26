#include<iostream>
#include<string>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

bool isPalindromic(int n){
  string s = to_string(n);
  int l = s.size();
  rep(i,0,l/2)if(s[i] != s[l-i-1]) return false;
  return true;
}

int main(){
  int A, B; cin >> A >> B;
  int answer = 0;
  rep(i,A,B+1)if(isPalindromic(i)) ++answer;
  cout << answer << endl;
  return 0;
}