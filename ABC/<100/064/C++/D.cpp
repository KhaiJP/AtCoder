#include<iostream>
#include<string>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  int N; cin >> N;
  string S; cin >> S;

  int excess_close = 0, n_close = 0;
  rep(i, 0, N){
    n_close += (S[i] == ')' ? 1 : -1);
    excess_close = max(excess_close, n_close);
  }
  string tmp = ""; rep(i, 0, excess_close) tmp += '(';
  S = tmp + S;

  int shortage_close = 0;
  rep(i, 0, S.size()){
    shortage_close += (S[i] == '(' ? 1 : -1);
  }

  rep(i, 0, shortage_close) S += ')';
  cout << S << endl;
  return 0;
}