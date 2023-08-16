#include<iostream>
#include<vector>
#include<atcoder/all>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define rrep(i, s, t) for(int i = (s); i >= (t); --i)

vector<int> E[200010];
int answer[200010];

int main(){
  int N, M; cin >> N >> M;
  atcoder::dsu uf(N);
  rep(i, 0, M){
    // 1-indexed -> 0-indexed
    int a, b; cin >> a >> b; --a, --b;
    E[a].push_back(b);
  }
  
  // there is 0 connected component when all the nodes are deleted
  answer[N-1] = 0;
  rrep(u, N-1, 1){
    int tmp = 0;
    // if node u is connected to node v > u, # of components decrease
    for(auto v : E[u])if(!uf.same(u, v)){
      ++tmp;
      uf.merge(u, v);
    } 
    answer[u-1] = answer[u] - tmp + 1;
  }
  
  rep(i, 0, N) cout << answer[i] << endl;
  return 0;
}