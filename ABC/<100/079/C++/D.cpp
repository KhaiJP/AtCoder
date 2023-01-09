#include<iostream>
#include<vector>
#include<set>
#include<queue>
using namespace std;
#define rep(i, s, t) for (int i = (s); i < (t); ++i)
const int pInf32 =  1000000000+7;

// to use this <queue> must be included
int Dijkstra(int s, int t, vector<int> &V, map<int,vector<int>> &E, vector<vector<int>> &W);

int main(){
  int H, W; cin >> H >> W;
  vector C(10, vector<int>(10)); rep(i,0,10)rep(j,0,10) cin >> C[i][j];
  vector A(H, vector<int>(W));  rep(r,0,H) rep(c,0,W)  cin >> A[r][c];
  vector<int> m(10,0);
  map<int, vector<int>> E;
  vector<int> V(10); rep(i,0,10) V[i] = i;
  rep(i,0,10)rep(j,0,10){
    if(i==j) continue;
    E[i].push_back(j);
  }
  rep(i,0,10){
    if(i == 1) continue;
    m[i] = Dijkstra(i, 1, V, E, C);
  }
  int answer = 0;
  rep(r,0,H)rep(c,0,W) answer += (A[r][c] == -1 ? 0 : m[A[r][c]]);
  cout << answer << endl;
  return 0;
}

int Dijkstra(int s, int t, vector<int> &V, map<int,vector<int>> &E, vector<vector<int>> &W){
  vector<int> dist(V.size(), pInf32);
  vector<bool> determined(V.size(), false);
  dist[s] = 0;
  priority_queue< pair<int,int>> q;
  q.push({-dist[s], s});
  while(!q.empty()){
    int d = -q.top().first;
    int u = q.top().second;
    q.pop();
    if(determined[u]) continue;
    dist[u] = d;
    determined[u] = true;
    for(auto v:E[u]){
      if(determined[v]) continue;
      int alt = dist[u] + W[u][v];
      if(alt < dist[v]){
        dist[v] = alt;
        // prev[v] = u;
        q.push({-dist[v],v});
      }
    }
  }
  return dist[t];
}