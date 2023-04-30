#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

vector<int> lightsR[1510], lightsC[1510], wallsR[1510], wallsC[1510];
bool Field[1510][1510];

int main(){
  int H, W, N, M; cin >> H >> W >> N >> M;
  rep(i, 0, N){
    int A, B; cin >> A >> B;
    lightsR[A].push_back(B);
    lightsC[B].push_back(A);
  }

  rep(i, 0, M){
    int C, D; cin >> C >> D;
    wallsR[C].push_back(D);
    wallsC[D].push_back(C);
  }

  rep(i, 1, H+1){
    // grid (i, 0) and (i, W+1) are considered to be walls
    wallsR[i].push_back(0), wallsR[i].push_back(W+1);
    sort(lightsR[i].begin(), lightsR[i].end());
    sort(wallsR[i].begin(), wallsR[i].end());
  }
  rep(j, 1, W+1){
    // grid (0, j) and (H+1, j) are considered to be walls
    wallsC[j].push_back(0), wallsC[j].push_back(H+1);
    sort(lightsC[j].begin(), lightsC[j].end());
    sort(wallsC[j].begin(), wallsC[j].end());
  }

  
  // make rows bright
  rep(i, 1, H+1){
    // R : the right most wall found so far
    int R = -1;
    for(int a : lightsR[i]){
      // index j, left(right) l(r), small s
      int jls = 0, jrs = wallsR[i].size();
      // find the nearest wall to a on the left by binary search
      while(jls + 1 < jrs){
        int jmid = (jls + jrs) / 2;
        if(wallsR[i][jmid] < a) jls = jmid;
        else jrs = jmid;
      }
      // ws is the nearest wall. if ws < R, light a has no effect
      int &ws = wallsR[i][jls];
      if(ws < R) continue;

      // index j, left(right) l(r), big b
      int jlb = 0, jrb = wallsR[i].size();
      // find the nearest wall to a on the right by binary search
      while(jlb + 1 < jrb){
        int jmid = (jlb + jrb) / 2;
        if(wallsR[i][jmid] > a) jrb = jmid;
        else jlb = jmid;
      }
      // wb is the nearest wall.
      int &wb = wallsR[i][jrb];
      // in row i, grids in segment (ws, wb) is bright
      rep(j, ws+1, wb) Field[i][j] = true;
      // update the right most wall 
      R = wb;
      if(R == W+1) break;
    }
  }

  // make columns bright by the same way as rows
  rep(j, 1, W+1){
    int D = -1;
    for(int a : lightsC[j]){
      int ius = 0, ids = wallsC[j].size();
      while(ius + 1 < ids){
        int imid = (ius + ids) / 2;
        if(wallsC[j][imid] < a) ius = imid;
        else ids = imid;
      }
      int &wu = wallsC[j][ius];
      if(wu < D) continue;

      int iub = 0, idb = wallsC[j].size();
      while(iub + 1 < idb){
        int imid = (iub + idb) / 2;
        if(wallsC[j][imid] > a) idb = imid;
        else iub = imid;
      }
      int &wd = wallsC[j][idb];
      rep(i, wu+1, wd) Field[i][j] = true;
      D = wd;
      if(D == H+1) break;
    }
  }

  // count all the bright grids
  int answer = 0; rep(i, 1, H+1)rep(j, 1, W+1) answer += Field[i][j];
  cout << answer << endl;

  return 0;
}