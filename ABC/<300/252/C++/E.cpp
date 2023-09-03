#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;
using ll = int64_t;
using P  = pair<ll, ll>;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

vector<ll> E[200010];
map<P, ll> W, road;
ll dist[200010], pre[200010], used[200010];

void Dijkstra(){
  priority_queue<P> q;
  q.push({0, 0});

  while(q.size()){
    ll d = -q.top().first, u = q.top().second;
    q.pop();
    if(d > dist[u]) continue;
    
    for(auto v : E[u])if(d + W[{u, v}] < dist[v]){
      dist[v] = d + W[{u, v}];
      pre[v] = u;
      q.push({-dist[v], v});
    }
  }
}

int main(){
  ll N, M; cin >> N >> M;
  rep(i, 1, M+1){
    ll a, b, c; cin >> a >> b >> c;
    E[a].push_back(b),  E[b].push_back(a);
    W[{a, b}] = W[{b, a}] = c;
    road[{a, b}] = road[{b, a}] = i;
  }

  rep(i, 1, N+1) dist[i] = 2e18;
  E[0].push_back(1);
  W[{0, 1}] = 0;
  Dijkstra();
  rep(i, 2, N+1){
    ll r = road[{i, pre[i]}];
    if(used[r]) continue;
    cout << r << ' ';
    used[r] = true;
  }
  cout << endl;
  return 0;
}