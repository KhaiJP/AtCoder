#include<iostream>
#include<set>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

bool F[120][120];
set<pair<int, int>> answer;

int main(){
  int N, M; cin >> N >> M;
  rep(r, 1, N+1)rep(c, 1, M+1){
    char s; cin >> s;
    F[r][c] = s == '#';
  }

  rep(tlr, 1, N+1)rep(tlc, 1, M+1){
    bool flag = true;
    rep(i, 0, 3){
      rep(j, 0, 3) flag = flag && F[tlr+i][tlc+j];
      flag = flag && !F[tlr+i][tlc+3];
    }
    rep(j, 0, 4) flag = flag && !F[tlr+3][tlc+j];

    rep(i, 0, 3){
      rep(j, 0, 3) flag = flag && F[tlr+6+i][tlc+6+j];
      flag = flag && !F[tlr+6+i][tlc+6-1];
    }
    rep(j, 0, 4) flag = flag && !F[tlr+6-1][tlc+5+j];

    if(flag) answer.insert({tlr, tlc});
  }

  for(auto p : answer) cout << p.first << ' ' << p.second << endl;
  return 0;
}