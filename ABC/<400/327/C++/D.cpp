#include<iostream>
#include<set>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

// let us consider a graph with N nodes and M edges(spanned between A[i] and B[i])
// if and only if this graph has 1 or more loops which possess odd number of nodes,
// then X cannot be constructed.
// whether a loop possess odd number of nodes is managed by parity

int N, M, A[200010], B[200010];
set<int> E[200010];
bool visited[200010], parity[200010], has_bad_loop;

void dfs(int me, int parent=-1){
  for(auto child : E[me])if(child != parent){
    if(visited[child]){
      if(parity[child] != parity[me]) continue;
      has_bad_loop = true;
      return ;
    }
    else{
      parity[child] = !parity[me];
      visited[child] = true;
      dfs(child, me);
    }
  }
  return ;
}

int main(){
  cin >> N >> M;
  rep(i, 0, M) cin >> A[i];
  rep(i, 0, M) cin >> B[i];
  rep(i, 0, M) E[A[i]].insert(B[i]), E[B[i]].insert(A[i]);

  rep(i, 1, N+1)if(!visited[i]){
    visited[i] = true;
    dfs(i);
  }

  cout << (has_bad_loop ? "No" : "Yes") << endl;
  return 0;
}