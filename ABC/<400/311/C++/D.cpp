#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int DR[] = {-1,  0,  1,  0, -1,  1,  1, -1};
int DC[] = { 0,  1,  0, -1,  1,  1, -1, -1};

bool F[220][220], passed[220][220], moved[220][220][4];
int N, M;

void dfs(int r, int c){
  rep(k, 0, 4)if(!moved[r][c][k] && F[r+DR[k]][c+DC[k]]){
    moved[r][c][k] = true;
    int nr = r, nc = c;
    while(F[nr+DR[k]][nc+DC[k]]){
      nr += DR[k], nc += DC[k];
      passed[nr][nc] = true;
    }
    dfs(nr, nc);
  }
}

int main(){
  cin >> N >> M;
  rep(r, 1, N+1){
    string S; cin >> S;
    rep(c, 1, M+1) F[r][c] = S[c-1] == '.';
  }
  
  passed[2][2] = true;
  dfs(2, 2);

  int answer = 0;
  rep(r, 1, N+1)rep(c, 1, M+1) answer += passed[r][c];
  cout << answer << endl;
  return 0;
}