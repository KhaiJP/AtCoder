#include<iostream>
#include<string>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  string S; cin >> S;
  int N = S.size();

  int64_t answer = 0;
  rep(i, 0, 1 << (N-1)){
    string s = "";

    rep(j, 0, N){
      s += S[j];
      if(i & (1 << j)){
        answer += stoll(s);
        s = "";
      }
    }

    answer += stoll(s);
  }

  cout << answer << endl;
  return 0;
}