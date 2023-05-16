#include<iostream>
#include<vector>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

vector<int> B[25];

int dfs(int i = 1){
  if(B[i].size() == 0) return 1;

  int M = 0, m = 1 << 30;
  for(auto b : B[i]){
    int pay = dfs(b);
    M = max(M, pay);
    m = min(m, pay);
  }

  return M + m + 1;
}

int main(){
  int N; cin >> N;
  rep(i, 2, N+1){
    int b; cin >> b;
    B[b].push_back(i);
  }

  cout << dfs() << endl;
  return 0;
}