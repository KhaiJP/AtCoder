#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define chmax(a, b) a = max(a, b)

int main(){
  int N, P1; cin >> N >> P1;
  int answer = 0;
  rep(i, 2, N+1){
    int  P; cin >> P; ++P;
    chmax(answer, max(P - P1, 0));
  }

  cout << answer << endl;
  return 0;
}