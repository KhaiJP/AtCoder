#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int h[110];

int main(){
  int N; cin >> N;
  rep(i, 0, N) cin >> h[i];

  int answer = 0, l = 0, r = 0;
  while(1){
    while(l < N && h[l] == 0) ++l;
    if(l == N) break;
    int mini = h[l];
    r = l;
    while(1){
      ++r;
      if(h[r] != 0) mini = min(mini, h[r]);
      if(h[r] == 0){
        answer += mini;
        rep(i, l, r) h[i] = h[i] - mini;
        break;
      }
    }
  }

  cout << answer << endl;
  return 0;
}