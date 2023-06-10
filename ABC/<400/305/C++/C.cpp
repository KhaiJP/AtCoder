#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

char F[510][510];
int DR[] = {-1,  0,  1,  0, -1,  1,  1, -1};
int DC[] = { 0,  1,  0, -1,  1,  1, -1, -1};

int main(){
  int H, W; cin >> H >> W;

  int R = 1000, C = 1000, RR = 0, CC = 0;
  rep(r, 1, H+1)rep(c, 1, W+1) cin >> F[r][c];
  rep(r, 1, H+1)rep(c, 1, W+1)if(F[r][c] == '.'){
    int hash = 0;
    rep(k, 0, 4) hash += F[r+DR[k]][c+DC[k]] == '#';
    if(hash > 1){
      cout << r << ' ' << c << endl;
      return 0;
    }
  }
}