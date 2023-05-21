#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

char F[110][110];
int DR[] = {-1,  0,  1,  0, -1,  1,  1, -1};
int DC[] = { 0,  1,  0, -1,  1,  1, -1, -1};
string snuke = "snuke";

int main(){
  int H, W; cin >> H >> W;
  rep(r, 0, H)rep(c, 0, W) cin >> F[r][c];

  rep(r, 0, H)rep(c, 0, W)if(F[r][c] == 's'){
    rep(k, 0, 8){
      int &dr = DR[k], &dc = DC[k];
      
      bool r_bound = r + 4*dr >= 0 && r + 4*dr < H;
      bool c_bound = c + 4*dc >= 0 && c + 4*dc < W;
      
      bool is_snuke = r_bound && c_bound;
      if(is_snuke)rep(j, 1, 5){
        is_snuke = is_snuke && F[r+j*dr][c+j*dc] == snuke[j];
      }

      if(is_snuke){
        rep(j, 0, 5) cout << r + j*dr + 1<< ' ' << c + j*dc + 1<< '\n';
        cout << endl;
        return 0;
      }
    }
  }
}