#include<iostream>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define fore(a, v) for(auto a : v)

// stores how many times rope i is used.
int n_used[200010];

int main(){
  int N, M; cin >> N >> M;
  
  dsu uf(N);
  // tie ropes and make groups. groups are monitored by union find.
  rep(i, 0, M){
    int A, C; char B, D;
    cin >> A >> B >> C >> D;
    --A, --C;
    ++n_used[A], ++n_used[C];
    uf.merge(A, C);
  }

  int n_loops = 0,   n_groups = uf.groups().size();

  // check if group g is loop
  fore(g, uf.groups()){
    bool isloop = true;
    // if group g is loop, all nodes in g mush be used twice
    fore(v, g) isloop = isloop && n_used[v] == 2;
    n_loops += isloop;
  }

  cout << n_loops << ' ' << n_groups - n_loops << endl;
  return 0;
}