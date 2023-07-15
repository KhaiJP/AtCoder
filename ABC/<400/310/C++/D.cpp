#include<iostream>
#include<set>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

// set of incompatible pair
set<pair<int, int>> S;
// set of team division; 
// 1. most inner set represents members of a team. eg {0, 3, 4}
// 2. second inner set represents a specific team division. eg {{0, 3, 4}, {1}, {2, 5}} (T = 3, N = 6)
set<set<set<int> > > R;
int t[11], N, T, M;

void dfs(int pre = 0){
  // all the members already belong to a team
  if(pre == N){
    // check if the player are divied into T temas
    set<int> tmp; rep(i, 0, N) tmp.insert(t[i]);
    if(tmp.size() != T) return ;
    
    // check if all the teams are peaceful
    bool flag = true;
    for(auto p : S){
      int a = p.first, b = p.second;
      flag = flag && t[a] != t[b];
      if(!flag) return ;
    }
    
    // check if same team division has not appeared before
    set<int> tmps[10];
    rep(i, 0, N) tmps[t[i]].insert(i);
    set<set<int>> wrap; rep(i, 0, T) wrap.insert(tmps[i]);
    R.insert(wrap);

    return ;
  }

  // assign member pre a team : pre can belong to 0, 1, ... , pre
  rep(i, 0, min(pre+1, T)){
    t[pre] = i;
    dfs(pre+1);
    t[pre] = -1;
  }

  return ;
}

int main(){
  cin >> N >> T >> M;
  rep(i, 0, M){
    int a, b; cin >> a >> b; --a, --b;
    S.insert({a, b});
  }
  rep(i, 0, 11) t[i] = -1;
  dfs();
  cout << R.size() << endl;
  return 0;
}