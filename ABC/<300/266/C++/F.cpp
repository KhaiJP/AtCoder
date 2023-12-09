#include<iostream>
#include<vector>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int N, Q, root[200010], s = 200005;
bool visited[200010], inloop[200010], found_loop;
vector<int> V, E[200010];

void find_loop(int u, int pre=-1){
  if(visited[u]){
    if(found_loop) return ;
    found_loop = true;
    bool f = false;
    for(auto a : V){
      if(!f && a == u){
        f = true;
      }
      if(f) inloop[a] = true;;
    }
    return ;
  }

  visited[u] = true;
  for(auto v : E[u])if(v != pre){
    V.push_back(v);
    find_loop(v, u);
    V.pop_back();
  }
}

void set_root(int u, int r, int pre=-1){
  root[u] = r;
  for(auto v : E[u])if(!inloop[v] && v != pre){
    set_root(v, r, u);
  }
}

int main(){
  cin >> N;
  rep(i, 0 ,N){
    int x, y; cin >> x >> y;
    E[x].push_back(y), E[y].push_back(x);
  }

  rep(i, 1, N+1)if(E[i].size() == 1){
    s = i;
    break;
  }

  find_loop(s);
  rep(i, 1, N+1)if(inloop[i]){
    set_root(i, i);
  }

  cin >> Q;
  while(Q--){
    int x, y; cin >> x >> y;
    if(root[x] != 0 && root[y] != 0 && root[x] == root[y]){
      cout << "Yes" << endl;
    }else{
      cout << "No" << endl;
    }
  }
  return 0;
}