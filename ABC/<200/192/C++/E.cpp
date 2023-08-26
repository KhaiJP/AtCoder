#include<iostream>
#include<queue>
#include<map>
#include<set>
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

set<ll> E[100010];
// key : city pair {A, B} with A < B, value set of {T, K}
map<P, set<P>> TK;
ll N, M, X, Y, dist[100010], inf = 2e18;

int main(){
  cin >> N >> M >> X >> Y;

  rep(i, 1, M+1){
    ll A, B, T, K; cin >> A >> B >> T >> K;
    if(B < A) swap(A, B);
    TK[{A, B}].insert({T, K});
    E[A].insert(B), E[B].insert(A);
  }
  
  rep(i, 1, N+1) dist[i] = inf;
  
  // Dijkstra-like method
  priority_queue<pair<ll, ll>> q;
  q.push({0, X});
  dist[X] = 0;
  while(q.size()){
    ll u = q.top().second, ct = -q.top().first;
    q.pop();
    // for some {T, K}, ct can be un-optimum
    if(ct > dist[u]) continue;

    for(auto v : E[u]){
      ll a = min(u, v), b = max(u, v), d = inf;
      for(auto p : TK[{a, b}]){
        ll T = p.first, K = p.second;
        ll quat = (ct + K - 1) / K;
        if(quat * K + T < d) d = quat * K + T;
      }
      if(d < dist[v]){
        dist[v] = d;
        q.push({-d, v});
      }
    }
  }

  cout << (dist[Y] < inf ? dist[Y] : -1) << endl;
  return 0;
}