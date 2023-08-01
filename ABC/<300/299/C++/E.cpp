#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

vector<int> E[2010];
int dist[2010][2010], p[2010], d[2010];
bool isblack[2010];

int main(){
  int N, M; cin >> N >> M;

  rep(i, 0, M){
    int u, v; cin >> u >> v;
    E[u].push_back(v), E[v].push_back(u);
  }
  

  int K; cin >> K;
  rep(i, 0, K) cin >> p[i] >> d[i];

  // set dist[u][v] : distance between u and v, by bfs
  rep(s, 1, N+1){
    queue<int> q; q.push(s);
    rep(v, 1, N+1)if(s != v) dist[s][v] = 1e9;

    while(q.size()){
      int u = q.front(); q.pop();
      for(auto v : E[u])if(dist[s][u]+1 < dist[s][v]){
        dist[s][v] = dist[s][u] + 1;
        q.push(v);
      }
    }
  }
  
  // make all the nodes white whose distances from p[i] are less than d[i]
  rep(i, 1, N+1) isblack[i] = true;
  rep(i, 0, K)rep(v, 1, N+1)if(dist[p[i]][v] < d[i]) isblack[v] = false;

  // check if the nearest black node from p[i] has distance d[i] 
  rep(i, 0, K){
    int nearest = 1e9;
    // if all the nodes are white, nearest remains 1e9 > d[i]
    rep(v, 1, N+1)if(isblack[v]) nearest = min(nearest, dist[p[i]][v]);
    
    if(nearest != d[i]){
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
  rep(i, 1, N+1) cout << isblack[i]; cout << endl;
  return 0;
}