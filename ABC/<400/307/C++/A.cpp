#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  int N; cin >> N;
  rep(i, 0, N){
    int answer = 0;
    rep(j, 0, 7){
      int A; cin >> A;
      answer += A;
    }
    cout << answer << ' ';
  }
  cout << endl;
  return 0;
}