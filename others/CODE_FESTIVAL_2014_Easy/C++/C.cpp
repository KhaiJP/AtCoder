#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

vector<int> E[1010];
int W[1010][1010], n, m, st[2], dist[2][1010], pre[2][1010];

int main(){
  cin >> n >> m >> st[0] >> st[1];
  rep(i, 0, m){
    int x, y, d; cin >> x >> y >> d;
    E[x].push_back(y),  E[y].push_back(x);
    W[x][y] = W[y][x] = d;
  }
  
  rep(l, 0, 2){
    priority_queue<pair<int,int>> q;
    int &s = st[l];
    rep(u, 0, 1010) dist[l][u] = 1e9;
    rep(u, 0, 1010) pre[l][u]  = -1;
    q.push({0, s});
    pre[l][s] = 0;
    while(q.size()){
      int d = -q.top().first, u = q.top().second;
      q.pop();
      if(d > dist[l][u]) continue;

      for(auto v : E[u])if(d + W[u][v] < dist[l][v]){
        dist[l][v] = d + W[u][v];
        pre[l][v]  = u;
        q.push({-dist[l][v], v});
      }
    }
  }
  
  rep(i, 1, n+1)if(dist[0][i] == dist[1][i] && dist[0][i] < 1e9 && dist[1][i] < 1e9){
    int mid = i;
    while(true){
      if(pre[0][mid] != pre[1][mid] && pre[0][mid] != -1 && pre[1][mid] != -1) break;
      mid = pre[0][mid];
    }
    cout << mid << endl;
    return 0;
  }

  cout << -1 << endl;
  return 0;
}