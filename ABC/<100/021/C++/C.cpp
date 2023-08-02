#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for (int i = (s); i < (t); ++i)

vector<int> E[110];
int N, M, a, b, dist[110];
const ll MOD = 1e9 + 7;
ll ways[110];

void solve() {
  rep(u, 0, N + 1) dist[u] = 1e9;
  ways[a] = 1;
  dist[a] = 0;

  queue<int> q;
  q.push(a);
  while(q.size()){
    int u = q.front();
    q.pop();
    for(auto v : E[u])if(dist[u] + 1 <= dist[v]){
      ways[v] = (ways[v] + ways[u]) % MOD;

      if(dist[u] + 1 == dist[v]) continue;

      dist[v] = dist[u] + 1;
      q.push(v);
    }
  }
}

int main(){
  cin >> N >> a >> b >> M;
  rep(i, 0, M){
    int a, b;
    cin >> a >> b;
    E[a].push_back(b), E[b].push_back(a);
  }

  solve();
  cout << ways[b] << endl;
  return 0;
}
