#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

ll N, M, T, A[100010], answer, dist[2][100010], inf = 1e18;
// E[0][u]: nomal edge from u. E[1][u]: inversed edge into u.
// same logic for weight W.
vector<ll> E[2][100010];
map<pair<ll, ll>, ll> W[2];

void Dijkstra(int f){
  rep(u, 0, 100010) dist[f][u] = inf;
  dist[f][1] = 0;
  priority_queue<pair<ll, ll>> q;
  q.push({-dist[f][1], 1});

  while(q.size()){
    ll d = -q.top().first, u = q.top().second;
    q.pop();
    if(d > dist[f][u]) continue;
    for(auto v : E[f][u])if(d + W[f][{u, v}] < dist[f][v]){
      dist[f][v] = d + W[f][{u, v}];
      q.push({-dist[f][v], v});
    }
  }
}

void solve(){
  Dijkstra(0);
  Dijkstra(1);

  rep(u, 1, N+1){
    ll travel_time = dist[0][u] + dist[1][u];
    ll gap = T - travel_time;
    if(gap <= 0) continue;
    answer = max(answer, gap * A[u]);
  }
}

int main(){
  cin >> N >> M >> T;
  rep(i, 1, N+1) cin >> A[i];
  rep(i, 0, M){
    ll a, b, c; cin >> a >> b >> c;
    E[0][a].push_back(b), E[1][b].push_back(a);
    W[0][{a,b}] = W[1][{b, a}] = c;
  }

  solve();

  cout << answer << endl;
  return 0;
}