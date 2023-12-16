#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

// let node u is connected to k leaf nodes. since each leaf node requires 
// single operation to erase them, node u requires k + 1 operations.
// suppose node 1 is connected to k nodes, k-1 nodes of them must be erased to make node 1 leaf.
// the number of operations to erase each of k nodes can be found by dfs
// the answer is the sum of k-1 numbers of operations + 1

vector<int> E[300010], V;
int N, answer;

int dfs(int me, int parent){
  int n = 0;
  for(auto child : E[me])if(child != parent){
    n += dfs(child, me);
  }
  return n + 1;
}

int main(){
  cin >> N;
  rep(i, 1, N){
    int u, v; cin >> u >> v;
    E[u].push_back(v),  E[v].push_back(u);
  }

  for(auto v : E[1]) V.push_back(dfs(v, 1));
  sort(V.begin(), V.end());
  
  int K = V.size();
  rep(i, 0, K-1) answer += V[i];

  cout << answer + 1 << endl;
  return 0;
}