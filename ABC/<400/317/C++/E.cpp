#include<iostream>
#include<queue>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int DR[] = {-1,  0,  1,  0, -1,  1,  1, -1};
int DC[] = { 0,  1,  0, -1,  1,  1, -1, -1};
string REF = "^>v<";

int sr, sc, gr, gc, H, W, dist[2010][2010], inf = 1e9;
char F[2010][2010];

int main(){
  cin >> H >> W;
  rep(r, 0, 2010)rep(c, 0, 2010) F[r][c] = '#';

  rep(r, 1, H+1)rep(c, 1, W+1){
    cin >> F[r][c];
    if(F[r][c] == 'S') sr = r, sc = c;
    if(F[r][c] == 'G') gr = r, gc = c;
  }
  F[sr][sc] = '.';
  F[gr][gc] = '.';

  // chage squares' state according to the persons
  rep(r, 1, H+1)rep(c, 1, W+1){
    int R = r, C = c;
    rep(k, 0, 4)if(F[r][c] == REF[k]){
      while(F[R+DR[k]][C+DC[k]] == '.' || F[R+DR[k]][C+DC[k]] == '!'){
        R += DR[k], C += DC[k];
        F[R][C] = '!';
      }
    }
  }

  // simple bfs
  rep(r, 1, H+1)rep(c, 1, W+1) dist[r][c] = inf;
  queue<pair<int, int>> q;
  q.push({sr, sc});
  dist[sr][sc] = 0;

  while(q.size()){
    int r = q.front().first, c = q.front().second;
    q.pop();
    int d = dist[r][c];
    
    rep(k, 0, 4){
      int nr = r + DR[k], nc = c + DC[k];
      if(F[nr][nc] == '.' && d+1 < dist[nr][nc]){
        dist[nr][nc] = d + 1;
        q.push({nr, nc});
      }
    }
  }

  cout << (dist[gr][gc] < inf ? dist[gr][gc] : -1) << endl;
  return 0;
}