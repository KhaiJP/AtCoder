#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int N;
string S, T;

int main(){
  cin >> S;
  N = S.size();

  rep(i, 0, N){
    T += S[i];
    if((int)T.size() >= 3 && T.substr(T.size()-3) == "ABC"){
      rep(j, 0, 3) T.pop_back();
    }
  }
  cout << T << endl;
  return 0;
}