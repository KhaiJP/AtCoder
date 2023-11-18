#include<iostream>
#include<set>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int N, Q, index[200010];
set<int> colours[200010];

int main(){
  cin >> N >> Q;
  rep(i, 1, N+1){
    int C; cin >> C;
    index[i] = i;
    colours[index[i]].insert(C);
  }

  while(Q--){
    int a, b; cin >> a >> b;
    int &id_a = index[a], &id_b = index[b];
    if(colours[id_a].size() > colours[id_b].size()){
      swap(id_a, id_b);
    }
    for(auto x : colours[id_a]){
      colours[id_b].insert(x);
    }
    colours[id_a].clear();
    cout << colours[id_b].size() << endl;
  }
  return 0;
}