#include<iostream>
#include<deque>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

bool path[110][110];
int dist[110][110];

int main(){
  int H, W; cin >> H >> W;
  rep(h, 1, H+1)rep(w, 1, W+1){
    char c; cin >> c;
    path[h][w] = c == '.';
  }
  if(!path[1][1]){
    cout << 0 << endl;
    return 0;
  }
  
  int answer = 1;
  // go down and go right
  pair<int, int> d[] = {{1,0}, {0,1}};
  deque<pair<int,int>> dq;
  dq.push_back({1,1});
  dist[1][1] = 1;

  while(!dq.empty()){
    int h = dq.front().first, w = dq.front().second;
    dq.pop_front();
    
    rep(i, 0, 2){
      int &nh = d[i].first, &nw = d[i].second;
      if(path[h + nh][w + nw] && dist[h + nw][w + nw] < dist[h][w] + 1){
        dist[h + nw][w + nw] = dist[h][w] + 1;
        dq.push_back({h + nw, w + nw});
        answer = max(answer, dist[h + nw][w + nw]);
      }
    }
  }
  
  cout << answer << endl;
  return 0;
}