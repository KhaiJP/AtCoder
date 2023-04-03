#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

// naive simulation; calculate the sum for every single query -> O(QN) : TLE
// using prefix sum; O(Q + N)
int score[2][100010], pfx[2][100010];

int main(){
  int N; cin >> N;
  rep(i, 1, N+1){
    int C, P; cin >> C >> P; --C;
    score[C][i] = P;
    rep(c, 0, 2) pfx[c][i] = pfx[c][i-1] + score[c][i];
  }

  int Q; cin >> Q;
  while(Q){
    int L, R; cin >> L >> R;
    cout << pfx[0][R] - pfx[0][L-1] << ' ' << pfx[1][R] - pfx[1][L-1] << '\n';
    --Q;
  }

  cout << endl;
  return 0;
}