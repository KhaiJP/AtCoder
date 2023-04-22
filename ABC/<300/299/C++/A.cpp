#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int pipes[2], star, pos;
int main(){
  int N; cin >> N;
  string S; cin >> S;

  rep(i, 0, N){
    if(S[i] == '|'){
      pipes[pos] = i;
      ++pos;
    }
    if(S[i] == '*'){
      star = i;
    }
  }

  cout << (pipes[0] < star && star < pipes[1] ? "in" : "out") << endl;

  return 0;
}