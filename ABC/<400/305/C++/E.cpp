#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

vector<int> E[200010];
int dist[200010];

int main(){
  int N, M, K; cin >> N >> M >> K;
  rep(i, 0, M){
    int a, b; cin >> a >> b;
    --a, --b;
    E[a].push_back(b), E[b].push_back(a);
  }

  priority_queue<pair<int,int>> pq;
  rep(i, 0, K){
    int p, h; cin >> p >> h;
    --p;
    dist[p] = h;
  }

  rep(i, 0, N){
    if(dist[i] == 0) dist[i] = -1;
    else pq.push({dist[i], i}); 
  }
  
  while(!pq.empty()){
    int h = pq.top().first, u = pq.top().second; pq.pop();
    if(h > dist[u]) continue;
    for(auto v : E[u])if(h-1 > dist[v]){
      dist[v] = h-1;
      if(dist[v] > 0) pq.push({dist[v], v});
    }
  }

  int G = 0;
  queue<int> q;
  rep(u, 0, N)if(dist[u] >= 0){
    ++G;
    q.push(u+1);
  }

  cout << G << '\n';
  while(!q.empty()){
    cout << q.front() << ' ';
    q.pop();
  }
  return 0;
}