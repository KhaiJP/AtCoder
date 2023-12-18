#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int H, W, F[60][60];
int DR[] = {1, 0, -1, 0};
int DC[] = {0, 1, 0, -1};

int main(){
  cin >> H >> W;
  rep(i, 1, H+1)rep(j, 1, W+1){
    char c; cin >> c;
    F[i][j] = c == '#';
  }

  rep(i, 1, H+1)rep(j, 1, W+1)if(F[i][j] > 0){
    int tmp = 0;
    rep(k, 0, 4) tmp += F[i+DR[k]][j+DC[k]];
    if(tmp == 0){
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
  return 0;
}