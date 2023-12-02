#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int N, S, M, L, answer = 1e9;

int main(){
  cin >> N >> S >> M >> L;
  rep(s, 0, 100)rep(m, 0, 100)rep(l, 0, 100){
    if(6*s + 8*m + 12*l >= N){
      answer = min(answer, s*S + m*M + l*L);
    }
  }
  cout << answer << endl;
  return 0;
}