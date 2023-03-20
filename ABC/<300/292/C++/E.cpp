#include<iostream>
#include<map>
#include<set>
#include<deque>
using namespace std;
using Edges = map<int, set<int>>;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define fore(a, v) for(auto a : v)

bool visited[2010];

int main(){
  int N, M; cin >> N >> M;
  Edges E;

  // spanning edges
  rep(m, 0, M){
    int u, v; cin >> u >> v;
    E[u].insert(v);
  }

  // see this -> https://atcoder.jp/contests/abc292/editorial/5874
  // let us consider the simplest case: a -> b -> c.
  // int this case we must add an edge a -> c.
  // next the second simplest case is to be considered; a -> b -> c -> d.
  // because of the same reason above we must add a->c, which leads to that we also must add a->d.
  // these two added edges do not effect other additions of edges from nodes ohter than a.
  int answer = 0;
  rep(i, 1, N+1){
    deque<int> dq;
    rep(j, 1, N+1) visited[j] = false;
    dq.push_back(i);
    visited[i] = true;

    while(!dq.empty()){
      int u = dq.front(); dq.pop_front();
      fore(v, E[u])if(!visited[v]){
        visited[v] = true;
        ++answer;
        dq.push_back(v);
      }
    }
  }

  cout << answer - M << endl;
  return 0;
}