#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

vector<int> E[400010];
int dist[400010];
int N, M;

int main(){
  cin >> N >> M;
  rep(u, 0, N){
    int A; cin >> A;
    rep(k, 0, A){
      int v; cin >> v; --v;
      E[M+u].push_back(v), E[v].push_back(M+u);
    }
  }
  
  rep(i, 1, N+M) dist[i] = 1e9;
  queue<int> q; q.push(0);
  while(!q.empty()){
    int u = q.front(); q.pop();
    for(auto v : E[u])if(dist[v] == 1e9){
      dist[v] = dist[u] + (v >= M);
      q.push(v);
    }
  }

  cout << (dist[M-1] < 1e9 ? dist[M-1]-1 : -1) << endl;
  return 0;
}