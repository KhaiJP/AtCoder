#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

char F[1010][1010];
int DR[] = {-1,  0,  1,  0, -1,  1,  1, -1};
int DC[] = { 0,  1,  0, -1,  1,  1, -1, -1};

int main(){
  int N; cin >> N;
  rep(r, 0, N)rep(c, 0, N) cin >> F[r][c];
  
  rep(r, 0, N)rep(c, 0, N)rep(m, 0, 8){
    int k = 2;
    bool flag = true;
    rep(l, 0, 6){
      int R = r + l*DR[m], C = c + l*DC[m];
      if(0<= R && R < N && 0 <= C && C < N){
        flag = flag && (F[R][C] == '#' || k > 0);
        k -= (F[R][C] == '.');
        if(!flag) break;
      }else{
        flag = false;
        break;
      }
    }
    if(flag){
        cout << "Yes" << endl;
        return 0;
    }
  }

  cout << "No" << endl;
  return 0;
}