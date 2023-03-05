#include<iostream>
#include<vector>
#include<unordered_map>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using Edges = unordered_map<int, vector<int>>;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define fore(a, v) for(auto a : v)
#define yes "Yes"
#define noo "No"

int main(){
  int n, m; cin >> n >> m;
  dsu uf(n);
  Edges E;
  rep(i, 0, m){
    int u, v; cin >> u >> v;
    --u, --v;
    E[u].push_back(v);
    E[v].push_back(u);
    uf.merge(u, v);
  }
  vector<vector<int>> gs = uf.groups();
  fore(g, gs){
    int ne = 0;
    fore(v, g) ne += E[v].size();
    if( ne != 2*g.size() ){
      cout << noo << endl;
      return 0;
    }
  }
  cout << yes << endl;
  return 0;
}