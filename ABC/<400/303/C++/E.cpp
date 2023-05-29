#include<iostream>
#include<set>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

set<int> E[200010];

int main(){
  int N; cin >> N;
  rep(i, 1, N){
    int u, v; cin >> u >> v;
    E[u].insert(v), E[v].insert(u);
  }

  multiset<int> answer;
  int k3 = 0;
  rep(i, 1, N+1)if(E[i].size() >= 3){
    answer.insert(E[i].size());
    k3 += E[i].size() + 1;
  }

  rep(i, 0, (N - k3) / 3) answer.insert(2);

  for(auto a : answer) cout << a << ' ';
  cout << endl;
  return 0;
}