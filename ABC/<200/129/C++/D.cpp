#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

// wallsR[i] : wall addresses of row i. wallsC[j] : wall addresses of column j 
vector<int> wallsR[2010], wallsC[2010];
char F[2010][2010];

int main(){
  int H, W; cin >> H >> W;
  
  // set field info into F
  rep(i, 1, H+1){
    string S; cin >> S;
    rep(j, 1, W+1) F[i][j] = S[j-1];
  }

  // push walls surrounding the field
  rep(i, 1, H+1) wallsR[i].push_back(0), wallsR[i].push_back(W + 1);
  rep(j, 1, W+1) wallsC[j].push_back(0), wallsC[j].push_back(H + 1);

  // set wall addresses into wallsR and wallsC
  rep(i, 1, H+1)rep(j, 1, W+1)if(F[i][j] == '#'){
    wallsR[i].push_back(j);
    wallsC[j].push_back(i);
  }

  // sort wallsR and wallsC for binary search
  rep(i, 1, H+1) sort(wallsR[i].begin(), wallsR[i].end());
  rep(j, 1, W+1) sort(wallsC[j].begin(), wallsC[j].end());


  // find the maximum by binary search -> O( HW * (logH + logW) )
  int answer = -1;
  rep(i, 1, H+1)rep(j, 1, W+1)if(F[i][j] == '.'){
    
    // find L and R : L is the right most wall on the left of F[i][j]
    int l = 0, r = wallsR[i].size() - 1;
    while(l+1 < r){
      int mid = (l + r) / 2;
      if(wallsR[i][mid] > j) r = mid;
      else l = mid;
    }

    int L = wallsR[i][l], R = wallsR[i][r];

    // find U and D : U is the lowert wall above the F[i][j]
    int u = 0, d = wallsC[j].size() - 1;
    while(u+1 < d){
      int mid = (u + d) / 2;
      if(wallsC[j][mid] > i) d = mid;
      else u = mid;
    }

    int U = wallsC[j][u], D = wallsC[j][d];
    // put the light on i,j 
    // -> F[i][L+1] ... F[i][R-1] and F[U+1][j] ... F[D-1][j] get bright
    answer = max(answer, ((R-1) - L) + ((D-1) - U) - 1);
  }

  cout << answer << endl;
  return 0;
}