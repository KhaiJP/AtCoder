#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  int N, T; cin >> N >> T;

  int64_t answer = 0;
  int close_time = 0, pre = 0;
  
  rep(i, 0, N){
    int A; cin >> A;
    answer += T - max(close_time-A, 0);
    close_time = A + T;
  }

  cout << answer << endl;
  return 0;
}