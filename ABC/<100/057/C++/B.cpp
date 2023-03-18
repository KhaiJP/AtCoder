#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int A[55], B[55], C[55], D[55];

int main(){
  int N, M; cin >> N >> M;
  rep(i, 0, N) cin >> A[i] >> B[i];
  rep(i, 0, M) cin >> C[i] >> D[i];

  rep(i, 0, N){
    int d = 1000000000, cp = -1;
    rep(j, 0, M) if( abs(A[i] - C[j]) + abs(B[i] - D[j]) < d ){
      d = abs(A[i] - C[j]) + abs(B[i] - D[j]);
      cp = j+1;
    }
    cout << cp << '\n';
  }

  cout << endl;
  return 0;
}