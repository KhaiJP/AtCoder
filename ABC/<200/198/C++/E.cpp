#include<iostream>
#include<vector>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int N, C[100010], memo[100010];
bool visited[100010], isgood[100010];
vector<int> E[100010];

void dfs(int me){
  visited[me] = true;
  
  int &col = C[me];
  if(memo[col] == 0) isgood[me] = true;
  ++memo[col];
  for(auto child : E[me])if(!visited[child]){
    dfs(child);
  }
  --memo[col];
  return ;
}

int main(){
  cin >> N;
  rep(i, 1, N+1) cin >> C[i];
  rep(i, 1, N){
    int a, b; cin >> a >> b;
    E[a].push_back(b), E[b].push_back(a);
  }

  dfs(1);
  rep(i, 1, N+1)if(isgood[i]) cout << i << endl;
  return 0;
}