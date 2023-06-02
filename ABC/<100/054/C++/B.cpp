#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

char pic[55][55], tml[55][55];

int main(){
  int N, M; cin >> N >> M;
  rep(i, 0, N)rep(j, 0, N) cin >> pic[i][j];
  rep(i, 0, M)rep(j, 0, M) cin >> tml[i][j];
  

  rep(i, 0, N-M+1)rep(j, 0, N-M+1){
    bool flag = true;
    
    rep(ii, 0, M)if(flag)rep(jj, 0, M)if(pic[i+ii][j+jj] != tml[ii][jj]){
      flag = false;
      break;
    }

    if(flag){
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;
  return 0;
}