#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

bool campus[14][14];

int main(){
  int H, W; cin >> H >> W;
  rep(r, 1, H+1)rep(c, 1, W+1){
    char tile; cin >> tile;
    campus[r][c] = tile == '#';
  }

  int n_nodes = 0;
  rep(r, 1, H+1)rep(c, 1, W+1){
    int cnt = 0;
    cnt += campus[r][c];
    cnt += campus[r+1][c];
    cnt += campus[r][c+1];
    cnt += campus[r+1][c+1];

    n_nodes += (cnt == 1 || cnt == 3);
  }

  cout << n_nodes << endl;
  return 0;
}