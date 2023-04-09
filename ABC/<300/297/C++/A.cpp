#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int T[110];

int main(){
  int N, D; cin >> N >> D;
  rep(i, 1, N+1) cin >> T[i];
  T[0] = -D;
  
  int answer = -1;
  rep(i, 1, N+1)if(T[i] - T[i-1] <= D){
    answer = T[i];
    break;
  }

  cout << answer << endl;
  return 0;
}