#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  int N, X, answer = 0;
  cin >> N >> X;
  rep(i, 0, N){
    int S; cin >> S;
    if(S <= X) answer += S;
  }
  cout << answer << endl;
  return 0;
}