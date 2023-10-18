#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

vector<int> E[110], pre[110];
int N, M, W[110][110], dist[110];
bool used[110][110];

int main(){
  cin >> N >> M;
  rep(i, 0, M){
    int a, b, c; cin >> a >> b >> c;
    W[a][b] = W[b][a] = c;
    E[a].push_back(b), E[b].push_back(a);
  }

  rep(s, 1, N+1){
    rep(u, 1, N+1){
      dist[u] = 1e9;
      pre[u].clear();
    }
    priority_queue<pair<int, int>> q;
    q.push({0, s});
    dist[s] = 0;

    while(q.size()){
      int u = q.top().second, d = -q.top().first;
      q.pop();
      if(d > dist[u]) continue;

      for(auto v : pre[u]) used[u][v] = used[v][u] = true;

      for(auto v : E[u])if(d + W[u][v] <= dist[v]){
        if(d + W[u][v] == dist[v]){
          pre[v].push_back(u);
          continue;
        }
        pre[v].clear();
        pre[v].push_back(u);
        dist[v] = d + W[u][v];
        q.push({-dist[v], v});
      }
    }
  }

  rep(u, 1, N)rep(v, u+1, N+1) M -= used[u][v];

  cout << M << endl;
  return 0;
}