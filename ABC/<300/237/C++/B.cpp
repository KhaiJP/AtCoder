#include<iostream>
#include<vector>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  int H, W; cin >> H >> W;
  vector A(H, vector<int>(W, 0));
  rep(h, 0, H)rep(w, 0, W) cin >> A[h][w];
  rep(w, 0, W){rep(h, 0, H) cout << A[h][w] << ' '; cout << '\n';}
  return 0;
}