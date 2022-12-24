#include<iostream>
#include<vector>
#include<map>
#include<deque>
#define rep(i, s, t) for(int i=(s); i<(t); ++i)
#define ll long long
using namespace std;

int main(){
  int N, Q; cin >> N >> Q;
  map<int, vector<int>> Edges;
  rep(i,0,N-1){
    int a, b; cin >> a >> b;
    if(Edges.count(a)==1)Edges[a].push_back(b);
    else Edges[a] = vector<int>{b};

    if(Edges.count(b)==1)Edges[b].push_back(a);
    else Edges[b] = vector<int>{a}; 
  }
  vector<int> group(N+1);
  deque<int> dq;
  dq.push_back(1);
  group[1] = 1;
  while(!dq.empty()){
    int u = dq.front(); dq.pop_front();
    for(const auto& v:Edges[u]){
      if(group[v]!=0) continue;
      dq.push_back(v);
      group[v] = group[u]==1 ? 2 : 1; 
    }
  }
  rep(i,0,Q){
    int c, d; cin >> c >> d;
    cout << (group[c]==group[d] ? "Town" : "Road" ) << endl;
  }
  return 0;
}