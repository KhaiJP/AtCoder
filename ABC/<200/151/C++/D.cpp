#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

char F[22][22];
// Solve by Floyd-Warshall algorithm
int FW[410][410];
int DR[] = {-1,  0,  1,  0, -1,  1,  1, -1};
int DC[] = { 0,  1,  0, -1,  1,  1, -1, -1};

int main(){
  int H, W; cin >> H >> W;
  rep(i, 0, H)rep(j, 0, W) cin >> F[i][j];
  int N = H*W;
  rep(u, 0, N)rep(v, 0, N) FW[u][v] = 1e9;

  rep(u, 0, N){
    int r = u/W, c = u%W;
    if(F[r][c] == '.'){
      FW[u][u] = 0;
      // check nearest 4 nodes around u = (r, c);
      rep(k, 0, 4){
        int R = r + DR[k],  C = c + DC[k];
        if(0 <= R  &&  R < H  &&  0 <= C  &&  C < W && F[R][C] == '.'){
          int v = R*W + C;
          FW[u][v] = FW[v][u] = 1;
        }
      }
    }
  }

  // Floyd-Warshall algorithm
  rep(k, 0, N)rep(u, 0, N)rep(v, 0, N){
    FW[u][v] = min(FW[u][v], FW[u][k]+FW[k][v]);
  }

  int answer = 0;
  rep(u, 0, N)rep(v, 0, N)if(FW[u][v] < 1e9) answer = max(answer, FW[u][v]);
  cout << answer << endl;
  return 0;
}