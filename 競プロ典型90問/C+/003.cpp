#include<iostream>
#include<vector>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

// Given graph is apparently a tree
// Once a node is determined to be the root, the maximum depth+1, 0-indexed, is the score.
// The answer, the maximum "maximum depth", is the diameter of the tree

vector<int> E[100010];
int depth[100010], N;

void dfs(int current, int pre = 0, int dep = 0){
  depth[current] = dep;
  for(auto next : E[current])if(next != pre){
    dfs(next, current, dep+1);
  }
}

pair<int, int> findMax(){
  int M = 0, index = 0;
  rep(i, 1, N+1)if(M < depth[i]){
    M = depth[i];
    index = i;
  }
  return {M, index};
}

int main(){
  cin >> N;

  rep(i, 0, N){
    int A, B; cin >> A >> B;
    E[A].push_back(B);
    E[B].push_back(A);
  }

  dfs(1);
  int leaf = findMax().second;
  rep(i, 1, N+1) depth[i] = 0;
  dfs(leaf);

  cout << findMax().first+1 << endl;
  return 0;
}