#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;
using ll = int64_t;
using P  = pair<ll, ll>;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

ll N, dist[200010], inf=1e18;
vector<ll> E[200010];
map<P, ll> W;
priority_queue<P> q;

int main(){
  cin >> N;
  rep(i, 1, N){
    ll A, B, X; cin >> A >> B >> X;
    if(W.count({i, i+1}) == 0){
      E[i].push_back(i+1);
      W[{i, i+1}] = A;
    }else{
      W[{i, i+1}] = min(W[{i, i+1}], A);
    }
    if(W.count({i, X}) == 0){
      E[i].push_back(X);
      W[{i, X}] = B;
    }else{
      W[{i, X}] = min(W[{i, X}], B);
    }
  }

  // Dijkstra
  rep(i, 0, 200010) dist[i] = inf;
  dist[1] = 0;
  q.push({-dist[1], 1});

  while(q.size()){
    ll d = -q.top().first, u = q.top().second;
    q.pop();
    if(d > dist[u]) continue;
    for(ll v : E[u]){
      ll w = W[{u, v}];
      if(d + w >= dist[v]) continue;
      dist[v] = d + w;
      q.push({-dist[v], v});
    }
  }

  cout << dist[N] << endl;
  return 0;
}