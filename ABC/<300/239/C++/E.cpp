#include<iostream>
#include<vector>
#include<set>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

// E[u] : neighbour node of u
vector<int> E[100010];
int X[100010];
// TOP20[u] : top 20 numbers written in the subtree u
multiset<int, greater<int>> TOP20[100010];

// TOP20 of leaf nodes are determined first -> dfs
void dfs(int me=1, int parent=0){
  // TOP20[me] is now empty. and insert X[me]
  TOP20[me].insert(X[me]);
  for(auto child : E[me])if(child != parent){
    dfs(child, me);
    // TOP20[me] = (top 20 numbers of the union U_child TOP20[child])
    for(auto x : TOP20[child]){
      TOP20[me].insert(x);
      // if TOP20[me].size() > 20 ,the maximum of K, the smallest is to be erased.
      if(TOP20[me].size() > 20) TOP20[me].erase(--TOP20[me].end());
    }
  }
}


int main(){
  int N, Q; cin >> N >> Q;
  // set X
  rep(i, 1, N+1) cin >> X[i];

  //add edges
  rep(i, 1, N){
    int A, B; cin >> A >> B;
    E[A].push_back(B);  E[B].push_back(A);
  }

  // set TOP20
  dfs();

  while(Q){
    int V, K; cin >> V >> K;
    auto itr = TOP20[V].begin();
    // get K-th biggest
    rep(i, 1, K) ++itr;
    cout << *itr << '\n';

    --Q;
  }

  cout << endl;
  return 0;
}