#include<iostream>
#include<string>
#include<vector>
#define rep(i,s,t) for(int i=(s); i<(t); ++i)
#define ren(i,s,t) for(int i=(s); i>=(t); --i)
using namespace std;

int main(){
  vector<string> S(10); rep(r,0,10) cin >> S[r];
  int A, B, C, D;
  rep(r,0,10){
    rep(c,0,10)if(S[r][c]=='#'){
      C=c+1;
      ren(c,9,0) if(S[r][c]=='#'){
        D=c+1;
        A=r+1;
        break;
      }
      r = 10;
      break;
    }
  }
  ren(r,9,0)if(S[r][C-1]=='#'){
    B=r+1;
    break;
  }
  cout << A << ' ' << B << '\n';
  cout << C << ' ' << D << endl;
  return 0;
}