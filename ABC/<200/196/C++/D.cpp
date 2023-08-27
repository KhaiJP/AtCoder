#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

bool F[20][20];
int H, W, A, B, answer;

void dfs(int r = 0, int c = 0, int n = 0){
  // reached the tree leaves
  if(r == H && c == W){
    answer += n == A;
    return ;
  }
  // goto next row
  if(c == W){
    dfs(r+1, 0, n);
    return ;
  }
  // point (r, c) is already ocupied
  if(!F[r][c]){
    dfs(r, c+1, n);
    return ;
  }

  // put a tatami vertically
  if(F[r+1][c] && n < A){
    F[r][c] = F[r+1][c] = false;
    dfs(r, c+1, n+1);
    F[r][c] = F[r+1][c] = true;
  }
  // put a tatami horizontally
  if(F[r][c+1] && n < A){
    F[r][c] = F[r][c+1] = false;
    dfs(r, c+1, n+1);
    F[r][c] = F[r][c+1] = true;
  }
  // not put a tatami
  dfs(r, c+1, n);
  
  return ;
}

int main(){
  cin >> H >> W >> A >> B;
  rep(r, 0, H)rep(c, 0, W) F[r][c] = true;

  dfs();
  cout << answer << endl;
  return 0;
}