#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  int N, T; cin >> N >> T;
  int answer = 10000000;
  bool isTLE = true;
  rep(i,0,N){
    int c, t; cin >> c >> t;
    if(t <= T && c < answer){answer = c; isTLE = false;}
  }
  if(isTLE) cout << "TLE" << endl;
  else cout << answer << endl;
  return 0;
}