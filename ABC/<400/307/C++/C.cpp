#include<iostream>
#include<vector>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int Ha, Hb, Hx, Wa, Wb, Wx;
void input(vector<vector<bool>> &v, int H, int W);
void trim(const vector<vector<bool>> &v, vector<vector<bool>> &u);

int main(){
  cin >> Ha >> Wa;
  vector A(Ha, vector<bool>(Wa)); input(A, Ha, Wa);
  cin >> Hb >> Wb;
  vector B(Hb, vector<bool>(Wb)); input(B, Hb, Wb);
  cin >> Hx >> Wx;
  vector X(Hx, vector<bool>(Wx)); input(X, Hx, Wx);
  vector<vector<bool>> tX;
  trim(X, tX);

  int H = Ha + Hb + Hx, W = Wa + Wb + Wx;
  vector C(H, vector<bool>(W, false));
  rep(ia, 0, H-Ha+1)rep(ja, 0, W-Wa+1)rep(ib, 0, H-Hb+1)rep(jb, 0, W-Wb+1){
    rep(i, 0, H )rep(j, 0, W ) C[i][j] = false;
    rep(i, 0, Ha)rep(j, 0, Wa) C[ia+i][ja+j] = C[ia+i][ja+j] || A[i][j]; 
    rep(i, 0, Hb)rep(j, 0, Wb) C[ib+i][jb+j] = C[ib+i][jb+j] || B[i][j];
    vector<vector<bool>> tC;
    trim(C, tC);
    if(tX == tC){
      cout << "Yes" << endl;
      return 0;
    } 
  }
  cout << "No" << endl;
  return 0;
}

void input(vector<vector<bool>> &v, int H, int W){
  rep(i, 0 ,H)rep(j, 0, W){
    char c; cin >> c;
    v[i][j] = c == '#';
  }
  return ;
}

void trim(const vector<vector<bool>> &v, vector<vector<bool>> &u){
  int H = v.size(), W = v[0].size();
  int mr = H, Mr = 0, mc = W, Mc = 0;
  rep(r, 0, H){
    bool flag = false;
    rep(c, 0, W) flag = flag || v[r][c];
    if(flag){ mr = min(mr, r); Mr = max(Mr, r); }
  }
  rep(c, 0, W){
    bool flag = false;
    rep(r, 0, H) flag = flag || v[r][c];
    if(flag){ mc = min(mc, c); Mc = max(Mc, c); }
  }

  int h = Mr - mr + 1, w = Mc - mc + 1;
  rep(r, 0, h){
    vector<bool> tmp(w);
    rep(c, 0, w) tmp[c] = v[mr+r][mc+c];
    u.push_back(tmp);
  }
  return ;
}