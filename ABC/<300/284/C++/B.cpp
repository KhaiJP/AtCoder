#include<iostream>
using namespace std;
#define rep(i, s, t) for (int i = (s); i < (t); ++i)

int main(){
  int T; cin >> T;
  rep(t,0,T){
    int N; cin >> N;
    int tmp = 0;
    rep(i,0,N){
      int a; cin >> a;
      if(a%2==1)++tmp;
    }
    cout << tmp << '\n';
  }
  return 0;
}