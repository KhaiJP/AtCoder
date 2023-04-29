#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

char A[33][33], B[33][33], T[33][33];
int H, W;

void roll(int axis){
  // roll upward
  if(axis == 0){
    rep(c, 0, W){
      rep(r, 0, H) T[r][c] = A[(r+1)%H][c];
      rep(r, 0, H) A[r][c] = T[r][c];
    }
  }
  // roll left
  if(axis == 1){
    rep(r, 0, H){
      rep(c, 0, W) T[r][c] = A[r][(c+1)%W];
      rep(c, 0, W) A[r][c] = T[r][c];
    }
  }
}

bool equivAB(){
  rep(r, 0, H)rep(c, 0, W)if(A[r][c] != B[r][c]) return false;
  return true;
}

int main(){
  cin >> H >> W;
  rep(i, 0, H)rep(j, 0, W) cin >> A[i][j];
  rep(i, 0, H)rep(j, 0, W) cin >> B[i][j];

  rep(i, 0, H){
    rep(j, 0, W){
      if(equivAB()){
        cout << "Yes" << endl;
        return 0;
      }
      roll(1);
    }
    roll(0);
  }

  cout << "No" << endl;
  return 0;
}