#include<iostream>
#include<queue>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)
#define NOT_USED_TRAIN 0
#define USED_TRAIN 1
#define SOURCE 1

ll N, A, B, C, D[1010][1010], dist[2][1010];
priority_queue<pair<ll, pair<ll, ll> > > q;

void Dijkstra(){
  rep(state, 0, 2)rep(u, 1, N+1) dist[state][u] = 2e18;
  dist[NOT_USED_TRAIN][SOURCE] = 0;
  q.push({0, {SOURCE, 0}});

  while(q.size()){
    ll d = -q.top().first, u = q.top().second.first, state = q.top().second.second;
    q.pop();
    if(d > dist[state][u]) continue;

    rep(v, 1, N+1)if(v != u){
      if(state == NOT_USED_TRAIN && d + D[u][v]*A < dist[NOT_USED_TRAIN][v]){
        dist[NOT_USED_TRAIN][v] = d + D[u][v]*A;
        q.push({-dist[NOT_USED_TRAIN][v], {v, NOT_USED_TRAIN}});
      }
      if(d + D[u][v]*B + C < dist[USED_TRAIN][v]){
        dist[USED_TRAIN][v] = d + D[u][v]*B + C;
        q.push({-dist[USED_TRAIN][v], {v, USED_TRAIN}});
      }
    }
  }

  return ;
}

int main(){
  cin >> N >> A >> B >> C;
  rep(u, 1, N+1)rep(v, 1, N+1) cin >> D[u][v];
  
  Dijkstra();
  cout << min(dist[NOT_USED_TRAIN][N], dist[USED_TRAIN][N]) << endl;
  return 0;
}