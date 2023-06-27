#include<iostream>
#include<iomanip>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int a[1010][1010];
int64_t answer, F[1010][1010];
bool determined[1010][1010];
int const MOD = 1000000007;
int DR[] = {-1,  0,  1,  0, -1,  1,  1, -1};
int DC[] = { 0,  1,  0, -1,  1,  1, -1, -1};
bool visited[1010][1010];

void dfs(int r, int c){
  if(determined[r][c]) return;
  ++F[r][c];

  rep(k, 0, 4){
    int nr = r + DR[k], nc = c + DC[k];
    if(a[r][c] < a[nr][nc])if(!determined[nr][nc]){
      dfs(nr, nc);
    }
  }
  rep(k, 0, 4){
    int nr = r + DR[k], nc = c + DC[k];
    if(a[r][c] < a[nr][nc]) F[r][c] = (F[r][c] + F[nr][nc]) % MOD;
  }
  determined[r][c] = true;
  return ;
}

int main(){
  int H, W; cin >> H >> W;
  rep(r, 1, H+1)rep(c, 1, W+1) cin >> a[r][c];
  rep(r, 1, H+1)rep(c, 1, W+1) dfs(r, c);
  rep(r, 1, H+1)rep(c, 1, W+1) answer = (answer + F[r][c]) % MOD;
  cout << answer << endl;
  return 0;
}