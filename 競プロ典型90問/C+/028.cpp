#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

// Note first index is y and the second is x.
// XY_plain[y][x] = k : there are k papers on [x, x+1)*[y, y+1)
int XY_plain[1010][1010];
// area[k] : the area that k-papers pile
int area[100010];

int main(){
  int N; cin >> N;
  
  // 2-dimensional prefix sum
  rep(i, 0, N){
    int lx, ly, rx, ry; cin >> lx >> ly >> rx >> ry;
    ++XY_plain[ly][lx];
    --XY_plain[ry][lx];
    --XY_plain[ly][rx];
    ++XY_plain[ry][rx];
  }

  // prefix sum along x-axis
  rep(y, 0, 1001)rep(x, 1, 1001) XY_plain[y][x] += XY_plain[y][x-1];
  // prefix sum along y-axis
  rep(x, 0, 1001)rep(y, 1, 1001) XY_plain[y][x] += XY_plain[y-1][x];

  rep(y, 0, 1001)rep(x, 0, 1001) ++area[XY_plain[y][x]];

  rep(k, 1, N+1) cout << area[k] << '\n';
  cout << endl;
  return 0;
}