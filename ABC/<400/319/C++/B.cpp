#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  int N; cin >> N;
  rep(i, 0, N+1){
    bool t = false;
    rep(j, 1, 10){
      if(N%j == 0 && i%(N/j) == 0){
        cout << j;
        t = true;
        break;
      }
    }
    if(!t) cout << '-';
  }
  cout << endl;
  return 0;
}