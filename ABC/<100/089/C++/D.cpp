#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int X_of_[90010], Y_of_[90010], A[310][310], dist[90010];
int H, W, D, Q, MAX;

void preprocess(){
  // initialize
  rep(i, 0, 90010) dist[i] = 1e9;
  // set distance
  rep(a, 1, MAX+1)if(dist[a] == 1e9){
    int x = X_of_[a], y = Y_of_[a];
    int value = a, d = 0;
    while(true){
      dist[value] = d;
      value += D;
      if(value > MAX) break;
      
      int nx = X_of_[value], ny = Y_of_[value];
      d += abs(nx - x) + abs(ny - y);
      x = nx, y = ny;
    }
  }
}

int main(){
  cin >> H >> W >> D;
  MAX = H*W;
  rep(i, 1, H+1)rep(j, 1, W+1){
    cin >> A[i][j];
    X_of_[A[i][j]] = i;
    Y_of_[A[i][j]] = j;
  }

  preprocess();

  cin >> Q;
  while(Q--){
    int L, R; cin >> L >> R;
    cout << dist[R] - dist[L] << endl;
  }
  return 0;
}