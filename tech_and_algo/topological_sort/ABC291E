#include<iostream>
#include<vector>
#include<deque>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

// this problem can be solved by topological sort
// let A_X < A_Y -> a directed edge XY is spanned
// the condition if A is unique <-> the topological sort is unique
// if the sorted array 2 -> 3 -> 1 (for input example 1), then A is 3 1 2
// since the sorted array means A2 < A3 < A1  i.e.  the A2(1st) = 1, A3(2nd) = 2 and A1(3rd) = 3.

// indeg_of[u] : the in degree of node u
int indeg_of[200010], A[200010];
// dests_of[u] : nodes {v} that directed edge uv is spanned
vector<int> dests_of[200010];

int main(){
  int N, M; cin >> N >> M;
  rep(i, 0, M){
    int X, Y; cin >> X >> Y;
    ++indeg_of[Y];
    dests_of[X].push_back(Y);
  }

  deque<int>  q;
  rep(u, 1, N+1)if(indeg_of[u] == 0) q.push_back(u);

  int pos = 1;
  while(!q.empty()){
    // if q.size() != 1, then topological sort is not unique
    if(q.size() != 1){
      cout << "No" << endl;
      return 0;
    }
    int u = q.front(); q.pop_front();
    // node u is appeared at position pos -> A[u] = pos as explained in line 12
    A[u] = pos;   ++pos;

    for(auto v : dests_of[u])if(--indeg_of[v] == 0) q.push_back(v);
  }

  cout << "Yes" << '\n';
  rep(i, 1, N+1) cout << A[i] << ' '; cout << endl;
  return 0;
}