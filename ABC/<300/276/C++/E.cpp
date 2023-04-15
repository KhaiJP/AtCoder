#include<iostream>
#include<deque>
#include<vector>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  int H, W; cin >> H >> W;

  int Sr, Sc;
  vector Field(H, vector<char>(W));
  vector tile_num(H, vector<int>(W, 0));

  rep(row, 0, H)rep(col, 0, W){
    char c; cin >> c;
    if(c == 'S') Sr = row, Sc = col;
    Field[row][col] = c;
  }

  int d[] = {-1, 0, 1, 0, 0, -1, 0, 1};

  rep(i, 0, 4){
    int sr = Sr + d[2*i], sc = Sc + d[2*i+1];
    if(sr < 0 || sr >= H || sc < 0 || sc >= W) continue;
    if(Field[sr][sc] == '#') continue;

    deque<pair<int,int>> q;
    q.push_back( {sr, sc} );
    tile_num[sr][sc] = i+1;

    while(!q.empty()){
      int r = q.front().first, c = q.front().second;
      q.pop_front();

      rep(j, 0, 4){
        int nr = r + d[2*j], nc = c + d[2*j+1];
        if(nr < 0 || nr >= H || nc < 0 || nc >= W) continue;
        if((nr == Sr && nc == Sc) || Field[nr][nc] == '#' || tile_num[nr][nc] == i + 1) continue;
        if(tile_num[nr][nc] > 0){
          cout << "Yes" << endl;
          return 0;
        }else{
          tile_num[nr][nc] = i + 1;
          q.push_back({nr, nc});
        }
      }
    }
  }

  cout << "No" << endl;
  return 0;
}