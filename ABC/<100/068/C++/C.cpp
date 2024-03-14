#include<iostream>
#include<set>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int N, M;
set<int> E[200010];

int main(){
  cin >> N >> M;
  rep(i, 0, M){
    int a, b; cin >> a >> b;
    E[a].insert(b), E[b].insert(a);
  }

  rep(i, 1, N+1)if(E[1].count(i) == 1 && E[N].count(i) == 1){
    cout << "POSSIBLE" << endl;
    return 0;
  }

  cout << "IMPOSSIBLE" << endl;
  return 0;
}