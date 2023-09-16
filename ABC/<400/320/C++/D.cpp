#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

vector<ll> E[200010];
map<P, P> D;
ll N, M, X[200010], Y[200010];
bool visited[200010];

int main(){
  cin >> N >> M;
  rep(i, 0, M){
    ll A, B, x, y; cin >> A >> B >> x >> y;
    E[A].push_back(B),  E[B].push_back(A);
    D[{A, B}] = {x, y}, D[{B, A}] = {-x, -y};
  }
  
  queue<int> q;
  q.push(1);
  visited[1] = true;

  // bfs
  while(q.size()){
    ll u = q.front(); q.pop();
    ll &x = X[u], &y = Y[u];

    for(auto v : E[u])if(!visited[v]){
      ll &dx = D[{u, v}].first, &dy = D[{u, v}].second;
      X[v] = x + dx,  Y[v] = y + dy;
      visited[v] = true;
      q.push(v); 
    }
  }

  rep(u, 1, N+1){
    if(visited[u])  cout << X[u] << ' ' << Y[u] << endl;
    if(!visited[u]) cout << "undecidable" << endl;
  }
  return 0;
}