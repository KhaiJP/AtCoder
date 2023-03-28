#include<iostream>
#include<vector>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

vector<int> E[2020];
int answer;
bool visited[2020];

void dfs(int current){
  ++answer;
  visited[current] = true;
  for(auto next : E[current])if(!visited[next]) dfs(next);
}

int main(){
  int N, M; cin >> N >> M;
  rep(i, 0, M){
    int A, B; cin >> A >> B;
    E[A].push_back(B);
  }

  rep(i, 1, N+1){
    rep(j, 1, N+1) visited[j] = false;
    dfs(i);
  }
  cout << answer << endl;
  return 0;
}