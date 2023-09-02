#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int potential[200010], N, M, K, G;
vector<int> E[200010];
priority_queue<pair<int,int>> q;

int main(){
  cin >> N >> M >> K;
  // Edge preparation
  rep(i, 0, M){
    int a, b; cin >> a >> b;
    E[a].push_back(b), E[b].push_back(a);
  }
  // Guards preparation. if potential[u] > 0, u is guarded
  rep(i, 0, K){
    int p, h; cin >> p >> h;
    potential[p] = h+1;
    q.push({h+1 , p});
    ++G;
  }
  // Dijkstra algo
  while(q.size()){
    int u = q.top().second, h = q.top().first;
    q.pop();
    if(potential[u] > h) continue;

    for(auto v : E[u])if(potential[v] < h - 1){
      // if v was not guarded, then increment G
      if(potential[v] == 0) ++G;
      potential[v] = h - 1;
      if(potential[v] > 1) q.push({h-1, v});
    }
  }

  cout << G << endl;
  rep(i, 1, N+1)if(potential[i]) cout << i << ' '; 
  cout << endl;
  return 0;
}