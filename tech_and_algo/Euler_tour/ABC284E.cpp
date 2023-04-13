#include<iostream>
#include<vector>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

vector<int> E[200010];
bool  visited[200010];
int answer;

void dfs(int me = 1){
  ++answer;

  visited[me] = true;
  for(auto child : E[me])if(!visited[child]){
    if(answer >= 1000000) return;
    dfs(child);
  }

  visited[me] = false;
}

int main(){
  int N, M; cin >> N >> M;

  rep(i, 0, M){
    int u, v; cin >> u >> v;
    E[u].push_back(v);   E[v].push_back(u);
  }

  dfs();

  cout << answer << endl;
  return 0;
}