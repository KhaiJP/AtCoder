#include<iostream>
#include<string>
#include<algorithm>
#define rep(i, s, t) for(int i=(s); i<(t); ++i)
using namespace std;

int main(){
  string S; cin >> S;
  reverse(S.begin(), S.end());
  int answer = 0;
  // whatever other than '0'
  char prev = '1';
  rep(i,0,S.size()){
    if(S[i]=='0' && prev=='0'){
    prev = '1';
    continue;
    }
    prev = S[i];
    answer += 1;
  }
  cout << answer << endl;
  return 0;
}