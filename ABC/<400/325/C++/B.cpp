#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int N, answer, W[1010], X[1010];

int main(){
  int N; cin >> N;
  rep(i, 0, N) cin >> W[i] >> X[i];

  rep(t, 0, 24){
    int tmp = 0;
    rep(i, 0, N){
      int local_time = (t + X[i]) % 24;
      if(9 <= local_time &&  local_time < 18) tmp += W[i];
    }
    answer = max(answer, tmp);
  }
  cout << answer << endl;
  return 0;
}