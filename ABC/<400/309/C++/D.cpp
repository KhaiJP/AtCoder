#include<iostream>
#include<vector>
#include<deque>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

vector<int> E[2][150010];
int dist[2][150010], N[2], M, max_dist[2];

int main(){
  cin >> N[0] >> N[1] >> M;
  
  rep(i, 0, M){
    int a, b; cin >> a >> b; --a, --b;
    if(a < N[0]) E[0][a].push_back(b), E[0][b].push_back(a);
    else{
      a -= N[0], b -= N[0];
      E[1][a].push_back(b), E[1][b].push_back(a);
    }
  }

  rep(i, 0, 2)rep(j, 0, N[i]) dist[i][j] = 1e9;
  dist[0][0] = 0, dist[1][N[1]-1] = 0;

  rep(i, 0, 2){
    deque<int> q;
    if(i == 0) q.push_back(0);
    if(i == 1) q.push_back(N[1]-1);

    while(q.size()){
      int u = q.front(); q.pop_front();
      for(auto v : E[i][u])if(dist[i][u] + 1 < dist[i][v]){
        dist[i][v] = dist[i][u] + 1;
        q.push_back(v);
      }
    }

    rep(j, 0, N[i]) max_dist[i] = max(max_dist[i], dist[i][j]);
  }

  cout << max_dist[0] + max_dist[1] + 1 << endl;
  return 0;
}