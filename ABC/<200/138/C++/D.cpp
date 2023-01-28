#include<iostream>
#include<vector>
#include<deque>
#include<unordered_map>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define fore(a, v) for(auto a : v)
using Edges = unordered_map<int, vector<int>>;

int   points[200010];
bool visited[200010];

int main(){
  int N, Q; cin >> N >> Q;
  Edges E;
  // set edges
  rep(i,1,N){
    int a, b; cin >> a >> b;
    E[a].push_back(b);
    E[b].push_back(a);
  }

  // add points
  rep(q, 0, Q){
    int p, x; cin >> p >> x;
    points[p] += x;
  }

  // bfs
  deque<int> dq;
  dq.push_back(1);
  visited[1] = true;
  while(!dq.empty()){
    int u = dq.front(); dq.pop_front();
    fore(v, E[u]){
      if(visited[v]) continue;
      visited[v] = true;
      points[v] += points[u];
      dq.push_back(v);
    }
  }
  rep(i,1,N+1) cout << points[i] << ' ';
  cout << endl;
  return 0;
}