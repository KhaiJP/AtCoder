#include<iostream>
#include<vector>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

vector<int> E[200010];
int L[200010], R[200010], id;
void dfs(int cu=0, int pre=-1){
  L[cu] = id+1; 
  for(auto next : E[cu])if(next != pre) dfs(next, cu);
  if(E[cu].size() == 1 && pre != -1) ++id;
  R[cu] = id;
}

int main(){
  int N; cin >> N;
  rep(i, 0, N-1){
    int u, v; cin >> u >> v; --u, --v;
    E[u].push_back(v);
    E[v].push_back(u);
  }

  dfs( );

  rep(i, 0, N) cout << L[i] << ' ' << R[i] << '\n';
  cout << endl;
  return 0;
}