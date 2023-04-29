#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

char C[110][110];
int ans[110];

int main(){
  int H, W; cin >> H >> W;
  pair<int, int> d[] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

  rep(i, 0, H)rep(j, 0, W){
    cin >> C[i][j];
  }

  rep(i, 0, H)rep(j, 0, W){
    if(C[i][j] != '#') continue;

    bool iscross = true;
    int level = 1000;

    rep(k, 0, 4){
      int di = d[k].first, dj = d[k].second;
      int n = 1;
      while(true){
        if(i + n*di < 0 || H <= i + n*di) break;
        if(j + n*dj < 0 || W <= j + n*dj) break;
        if(C[i + n*di][j + n*dj] == '#') ++n;
        else break;
      }

      if(n == 1){
        iscross = false;
        break;
      }

      level = min(level, n-1);
    }
    if(iscross) ++ans[level];
  }

  rep(i, 1, min(H, W)+1) cout << ans[i] << ' ';
  cout << endl;
  return 0;
}