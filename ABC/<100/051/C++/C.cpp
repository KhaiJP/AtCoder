#include <iostream>
#define rep(i, s, t) for (int i = (s); i < (t); ++i)
using namespace std;

int main(){
  int sx, sy, tx, ty; cin >> sx >> sy >> tx >> ty;
  rep(dx,0,tx-sx) cout << 'R';
  rep(dy,0,ty-sy) cout << 'U';
  rep(dx,0,tx-sx) cout << 'L';
  rep(dy,0,ty-sy+1) cout << 'D';
  rep(dx,0,tx-sx+1) cout << 'R';
  rep(dy,0,ty-sy+1) cout << 'U';
  cout << 'L' << 'U';
  rep(dx,0,tx-sx+1) cout << 'L';
  rep(dy,0,ty-sy+1) cout << 'D';
  cout << 'R' << endl;
  return 0;
}