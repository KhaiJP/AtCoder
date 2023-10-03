#include<iostream>
#include<queue>
#include<set>
#include<map>
using namespace std;
using P  = pair<int, int>; 
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

set<int> E[100010], used[100010];
int N, K, colour[100010];
map<P, int> m;
bool visited[100010];

int main(){
  cin >> N;
  rep(i, 1, N){
    int u, v; cin >> u >> v;
    E[u].insert(v), E[v].insert(u);
    m[{u,v}] = m[{v,u}] = i;
  }

  rep(u, 1, N+1) K = max(K, (int)E[u].size());
  
  queue<int> q; q.push(1);
  visited[1] = true; 
  while(q.size()){
    int u = q.front(); q.pop();
    int col = 1;
    for(auto v : E[u])if(!visited[v]){
      visited[v] = true;
      while(used[u].count(col) == 1) ++col;
      used[u].insert(col), used[v].insert(col);
      colour[m[{u,v}]] = col;
      q.push(v);
    }
  }

  cout << K << endl;
  rep(i, 1, N) cout << colour[i] << endl;
  return 0;
}