#include<iostream>
#include<deque>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
const int inf32 =  1000000000+7;

int dist[51][51];
bool mp[51][51];
const pair<int,int> nxt[] = {{-1,0}, {0,1}, {1,0}, {0,-1}};

int main(){
  int H, W; cin >> H >> W;
  int num_whites = 0;
  rep(h,0,H)rep(w,0,W){
    char grid; cin >> grid;
    if(grid == '.'){
      mp[h][w] = true;
      ++num_whites;
    }
    dist[h][w] = inf32;
  }

  if(!mp[0][0] || !mp[H-1][W-1]){
    cout << -1 << endl;
    return 0;
  }

  deque<pair<int, int>> dq;
  dq.push_back( {0, 0} );
  dist[0][0] = 0;

  while(!dq.empty()){
    int h = dq.front().first, w = dq.front().second; dq.pop_front();
    rep(i,0,4){
      const int dh = nxt[i].first, dw = nxt[i].second;
      if(0 <= h+dh  &&  h+dh < H    &&    0 <= w+dw  &&  w+dw < W){
        if(mp[h+dh][w+dw] && dist[h][w] + 1 < dist[h+dh][w+dw]){
          dist[h+dh][w+dw] = dist[h][w]+1;
          dq.push_back( {h+dh, w+dw} );
        }
      }
    }
  }

  if(dist[H-1][W-1] == inf32){
    cout << -1 << endl;
    return 0;
  }
  
  cout << num_whites - dist[H-1][W-1] - 1 << endl; 
  return 0;
}