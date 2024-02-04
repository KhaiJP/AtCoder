#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int DR[] = {-1,  0,  1,  0};
int DC[] = { 0,  1,  0, -1};
int H, W, N, d, r, c;
bool F[110][110]; // false -> '.' = white, true -> '#' = black

int main(){
  cin >> H >> W >> N;
  while(N--){
    F[r][c] = !F[r][c];
    int coef = F[r][c] ? 1 : -1;
    d = (d + coef + 4) % 4;
    r = (r + DR[d] + H) % H;
    c = (c + DC[d] + W) % W;
  }

  rep(i, 0, H){
    rep(j, 0, W) cout << (F[i][j] ? '#' : '.');
    cout << endl;
  }
  return 0;
}