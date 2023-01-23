#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  int N, A, B; cin >> N >> A >> B;
  bool white = true;
  rep(r, 0, N){
    rep(a, 0, A){
      bool tmpwhite = white;
      rep(c, 0 , N){
        rep(b, 0 , B) cout << (tmpwhite ? '.' : '#');
        tmpwhite = !tmpwhite;
      }
      cout <<'\n';
    }
    white = !white;
  }
  cout << endl;
  return 0;
}