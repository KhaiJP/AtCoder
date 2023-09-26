#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

char F[110][110], changed_to_black[110][110];
int H, W;
int DR[] = {-1,  0,  1,  0, -1,  1,  1, -1};
int DC[] = { 0,  1,  0, -1,  1,  1, -1, -1};

int main(){
  cin >> H >> W;
  rep(r, 1, H+1)rep(c, 1, W+1) cin >> F[r][c];

  rep(r, 1, H+1)rep(c, 1, W+1)if(F[r][c] == '#'){
    bool is_white_around = false;
    rep(k, 0, 8) is_white_around = is_white_around || F[r+DR[k]][c+DC[k]] == '.';
    if(is_white_around) changed_to_black[r][c] += true;
  }

  rep(r, 1, H+1)rep(c, 1, W+1)if(changed_to_black[r][c]) F[r][c] = '.';
  
  rep(r, 1, H+1)rep(c, 1, W+1)if(changed_to_black[r][c]){
    bool is_black_around = false;
    rep(k, 0, 8) is_black_around = is_black_around || F[r+DR[k]][c+DC[k]] == '#';
    if(!is_black_around){
      cout << "impossible" << endl;
      return 0;
    }
  }
  cout << "possible" << endl;
  rep(r, 1, H+1){
    rep(c, 1, W+1) cout << F[r][c];
    cout << endl;
  }
  return 0;
}