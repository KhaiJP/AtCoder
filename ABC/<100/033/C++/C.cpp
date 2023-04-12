#include<iostream>
#include<string>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  string S; cin >> S; S += '+';
  int answer = 0;
  bool is0there = false;
  rep(i, 0, S.size()){
    if(i&1){
      if(S[i] == '+'){
        answer += !is0there;
        is0there = false;
      }
    }
    else is0there = is0there || S[i] == '0';
  }

  cout << answer << endl;
  return 0;
}