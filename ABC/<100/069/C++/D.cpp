#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int F[110][110];

int main(){
  int H, W, N; cin >> H >> W >> N;

  int k = 0;
  rep(c, 0, N){
    int a; cin >> a;
    while(a--){
      int i = k/W, j = k%W;
      F[i][j] = c+1;
      ++k;
    }
  }

  rep(i, 0, H){
    rep(j, 0, W) cout << (i&1 ? F[i][W-1 -j] : F[i][j]) << ' ';
    cout << endl;
  }

  return 0;
}