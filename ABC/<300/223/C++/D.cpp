#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

// this problem can be solved by the concept of topological sort.
// Ai appears prior to Bi -> a directed edge Ai-Bi is spanned.

// indeg_of[u] : the in degree of node u
int indeg_of[200010], answer[200010];
// dests_of[u] : nodes {v} that directed edge uv is spanned
vector<int> dests_of[200010];

int main(){
  int N, M; cin >> N >> M;

  rep(i, 0, M){
    int A, B; cin >> A >> B;
    ++indeg_of[B];
    dests_of[A].push_back(B);
  }

  priority_queue<int, vector<int>, greater<int>> q;
  rep(u, 1, N+1)if(indeg_of[u] == 0) q.push(u);

  int pos = 0;
  while(!q.empty()){
    int u = q.top(); q.pop();
    answer[pos] = u;  ++pos;

    for(auto v : dests_of[u])if(--indeg_of[v] == 0) q.push(v);
  }
  
  if(pos != N) cout << -1;
  else rep(i, 0, N) cout << answer[i] << ' ';
  cout << endl;
  return 0;
}