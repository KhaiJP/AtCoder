#include<iostream>
#include<vector>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

vector<int> E[200010];
int N;
string answer;
bool visited[200010];

// Euler tour like method
void dfs(int u = 1){
  visited[u] = true;
  for(auto v : E[u])if(!visited[v]){
    visited[v] = true;
    dfs(v);
  }
  if(u != 1) answer += to_string(u) + " ";
  return ;
}

int main(){
  cin >> N;
  rep(i, 1, N+1){
    int C;cin >> C;
    rep(_, 0, C){
      int P; cin >> P;
      E[i].push_back(P);
    }
  }

  dfs();
  cout << answer << endl;
  return 0;
}