#include<iostream>
#include<map>
#include<vector>
#include<deque>
#define rep(i,s,n) for(int i=(s);i<(n); ++i)
using namespace std;

int main(){
  int N, X, Y; cin >> N >> X >> Y;
  map<int, int> Prev;
  map<int, vector<int>> Edge;
  rep(i,0,N){
    int u, v; cin >> u >> v;
    if(Edge.count(u)==1) Edge[u].push_back(v);
    else Edge[u] = {v};
    if(Edge.count(v)==1) Edge[v].push_back(u);
    else Edge[v] = {u};
  }
  deque<int> q;
  q.push_back(Y);
  Prev[Y] = 0;
  while (!q.empty()){
    int u = q.front(); q.pop_back();
    if(Edge.count(u)==0) continue;
    rep(i,0,Edge[u].size()){
      int v = Edge[u][i];
      if(Prev.count(v)==1) continue;
      Prev[v] = u;
      if(v == X){
        while(v!= 0){
          cout << v << ' ';
          v = Prev[v];
        }
        cout << endl;
        return 0;
      }
      q.push_back(v);
    }
  }
}
