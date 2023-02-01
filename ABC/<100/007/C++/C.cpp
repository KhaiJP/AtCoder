#include<iostream>
#include<deque>
#include<map>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define RC_MAX 51
bool isWallAt[RC_MAX][RC_MAX];
int  dist[RC_MAX][RC_MAX];
const int inf32 =  1000000000+7;


int main(){
  map< int, pair<int, int> > direction;
  direction[0] = {-1,  0}; // go up
  direction[1] = { 0,  1}; // go right
  direction[2] = { 1,  0}; // go donw
  direction[3] = { 0, -1}; // go left

  int R, C; cin >> R >> C;
  int sr, sc; cin >> sr >> sc;
  int gr, gc; cin >> gr >> gc;
  
  // set walls
  rep(r, 1, R+1)rep(c, 1, C+1){
    char isWall; cin >> isWall;
    isWallAt[r][c] = ( isWall == '#' );
    dist[r][c] = inf32;
  }

  // bfs preperation
  deque< pair<int, int> > dq;
  dq.push_back( {sr, sc} );
  dist[sr][sc] =  0;

  // bfs application
  while (!dq.empty()){
    // current row and column
    int     &r = dq.front().first,     &c = dq.front().second;
    dq.pop_front();

    rep(d, 0, 4){
      // short for next next row and next column
      int nr = r + direction[d].first,   nc = c + direction[d].second;
      // check if nr and nc are within the labyrinth
      bool isnrValid = ( 1 <= nr && nr <= R );
      bool isncValid = ( 1 <= nc && nc <= C );
      if(  !isnrValid  ||   !isncValid  ) continue;
      // check if there is not wall
      if( isWallAt[nr][nc] ) continue;
      // check if already visited
      if(dist[nr][nc] <= dist[r][c] + 1) continue;

      dist[nr][nc] = dist[r][c] + 1;

      if(nr == gr && nc == gc){
        cout << dist[nr][nc] << endl;
        return 0;
      }

      dq.push_back( {nr,  nc} );
    }
  }
}