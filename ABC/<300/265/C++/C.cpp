#include<iostream>
#include<vector>
#define rep(i,s,t) for(int i=(s); i<(t); ++i)
using namespace std;

int main(){
  int H, W; cin >> H >> W;
  
  vector G(H, vector<char>(W));
  rep(h,0,H)rep(w,0,W) cin >> G[h][w];
  
  vector visited(H, vector<bool>(W, false));

  int r = 0, c = 0;
  while(true){
    if(visited[r][c]){
      cout << -1 << endl;
      return 0;
    }
    visited[r][c] = true;
    char &d = G[r][c];
    if     (d == 'U' && r != 0)   r -= 1;
    else if(d == 'D' && r != H-1) r += 1;
    else if(d == 'L' && c != 0)   c -= 1;
    else if(d == 'R' && c != W-1) c += 1;
    else break;
  }
  cout << r+1 << ' ' << c+1 << endl;
  return 0;
}