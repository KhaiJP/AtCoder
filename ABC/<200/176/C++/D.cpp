#include<iostream>
#include<algorithm>
#include<deque>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

bool F[1020][1020];
int H, W, Ch, Cw, Dh, Dw, dist[1020][1020];
int DR[] = {-1,  0,  1,  0, -1,  1,  1, -1};
int DC[] = { 0,  1,  0, -1,  1,  1, -1, -1};

bool is_valid_square(int r, int c){
  return 0 < r && r <= H && 0 < c && c <= W;
}

int main(){
  cin >> H >> W >> Ch >> Cw >> Dh >> Dw;
  rep(r, 1, H+1)rep(c, 1, W+1){
    char s; cin >> s;
    F[r][c] = s == '.';
  }

  rep(r, 0, 1020)rep(c, 0, 1020) dist[r][c] = 1e9;
  dist[Ch][Cw] = 0;
  deque<pair<int, int>> q; q.push_back({Ch, Cw});
  
  while(q.size()){
    int ur = q.back().first, uc = q.back().second;
    q.pop_back();
    
    // dfs for adjacent squares
    rep(k, 0, 4){
      int vr = ur + DR[k], vc = uc + DC[k];
      if(F[vr][vc] && dist[ur][uc] < dist[vr][vc]){
        dist[vr][vc] = dist[ur][uc];
        q.push_back({vr, vc});
      }
    }

    // bfs for remote squares
    rep(dr, -2, 3)rep(dc, -2, 3){
      int vr = ur + dr, vc = uc + dc;
      if(!is_valid_square(vr,vc)) continue;
      if(F[vr][vc] && dist[ur][uc] + 1 < dist[vr][vc]){
        dist[vr][vc] = dist[ur][uc] + 1;
        q.push_front({vr, vc});
      }
    }
  }
  
  cout << (dist[Dh][Dw] == 1e9 ? -1 : dist[Dh][Dw]) << endl;
}