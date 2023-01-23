#include<iostream>
using namespace std;
#define rep(i, s, t) for (int i = (s); i < (t); ++i)

int T[5][5], C[5];
int N, K;

int main(){
  cin >> N >> K;
  rep(n,0,N)rep(k,0,K) cin >> T[n][k];

  // N-digit of base-K number uniquely corresponds to each choice pattern
  int UL = 1;
  rep(i,0,N) UL *= K;

  rep(x,0,UL){
    int y = x;
    rep(i,0,N){
      C[i] = T[i][y%K];
      y /= K;
    }
    // 0 is the neutral element with respect to XOR calculation
    int checker = 0;
    rep(i,0,N) checker = checker ^ C[i];
    if(checker == 0){
      cout << "Found" << endl;
      return 0;
    }
  }
  cout << "Nothing" << endl;
  return 0;
}