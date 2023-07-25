#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

bool F[10][10];

int main(){
  rep(r, 0, 9){
    string S; cin >> S;
    rep(c, 0, 9) F[r][c] = S[c] == '#';
  }

  int answer = 0;
  rep(tlr, 0, 9)rep(tlc, 0, 9)if(F[tlr][tlc]){
    rep(trr, 0, tlr+1)rep(trc, tlc+1, 9)if(!(tlr == trr && tlc == trc) && F[trr][trc]){
      int deltar = trr - tlr, deltac = trc - tlc;
      int brr = trr + deltac, brc = trc - deltar;
      if(brr < 0 || 9 < brr || brc < 0 || 9 < brc || !F[brr][brc]) continue;
      int blr = brr - deltar, blc = brc - deltac;
      if(blr < 0 || 9 < blc || blc < 0 || 9 < blc || !F[blr][blc]) continue;
      ++answer;
    }
  }

  cout << answer << endl;
  return 0;
}