#include<iostream>
#include<vector>
#include<map>
#include<deque>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

vector<int> E[200010];

bool isBiGraph(vector<int> &V){
  vector<int> colour(V.size(), -1);
  map<int, int> convertor;
  rep(i, 0, V.size()) convertor[V[i]] = i;

  colour[0] = 0;
  deque<int> q; q.push_back(V[0]);
  while(q.size()){
    int u = q.front(); q.pop_front();
    int u_index = convertor[u];
    int clr = colour[u_index];
    for(auto v : E[u]){
      int v_index = convertor[v];
      if(colour[v_index] == clr) return false;
      if(colour[v_index] == 1 - clr) continue;
      colour[v_index] = 1 - clr;
      q.push_back(v);
    }
  }
  return true;
}

int main(){
  int N, M; cin >> N >> M;
  dsu uf(N);
  rep(i, 0, M){
    int A, B; cin >> A >> B; --A, --B;
    uf.merge(A, B);
    E[A].push_back(B),  E[B].push_back(A);
  }

  if(uf.groups().size() > 1){
    cout << "No" << endl;
    return 0;
  }

  bool isbigraph = isBiGraph(uf.groups()[0]);
  cout << (isbigraph ? "Yes" : "No") << endl;
  return 0;
}