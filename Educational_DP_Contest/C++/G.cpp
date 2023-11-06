#include<iostream>
#include<queue>
#include<vector>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

ll N, M, indeg[100010], dist[100010], answer;
vector<ll> E[100010];

int main(){
  cin >> N >> M;
  rep(i, 0, M){
    ll x, y; cin >> x >> y;
    ++indeg[y];
    E[x].push_back(y);
  }

  queue<ll> q;
  rep(u, 1, N+1)if(indeg[u] == 0) q.push(u);

  while(q.size()){
    ll u = q.front(), d = dist[u];
    q.pop();
    for(auto v : E[u]){
      dist[v] = max(dist[v], d + 1);
      --indeg[v];
      if(indeg[v] == 0) q.push(v);
    }
  }

  rep(u, 1, N+1) answer = max(answer, dist[u]);
  cout << answer << endl;
  return 0;
}