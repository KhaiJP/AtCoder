#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  int N, M; cin >> N >> M;
  string S, T; cin >> S >> T;
  string prefix = "", postfix = "";
  rep(i, 0, N) prefix += T[i];
  rep(i, M-N, M) postfix += T[i];
  
  if(S == prefix && S == postfix){
    cout << 0 << endl;
    return 0;
  }
  if(S == prefix){
    cout << 1 << endl;
    return 0;
  }
  if(S == postfix){
    cout << 2 << endl;
    return 0;
  }
  cout << 3 << endl;
  return 0;
}