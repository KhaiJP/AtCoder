#include<iostream>
#include<vector>
#include<map>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

vector<int> E[100010];
map<pair<int, int>, bool> W;
int colour[100010], N;

void dfs(int u){
  for(auto v : E[u])if(colour[v] == -1){
    colour[v] = W[{u, v}] ? 1 - colour[u] : colour[u];
    dfs(v);
  }
  return ;
}

int main(){
  cin >> N;
  rep(i, 0, N+1) colour[i] = -1;
  rep(i, 1, N){
    int u, v, w; cin >> u >> v >> w;
    E[u].push_back(v), E[v].push_back(u);
    W[{u,v}] = W[{v,u}] = w&1;
  }
  
  colour[1] = 0;
  dfs(1);
  rep(i, 1, N+1) cout << colour[i] << endl;
  return 0;
}