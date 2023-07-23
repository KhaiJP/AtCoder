#include<iostream>
#include<queue>
#include<set>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

set<int> in[200010];
int out[200010];
bool noin[200010];

void erase(int u, int v){
  noin[u] = true;
  in[v].erase(u);
  if(in[v].size() == 0) erase(v, out[v]);
  return ;
}

int main(){
  int N; cin >> N;
  rep(i, 0, N){
    int A; cin >> A; --A;
    in[A].insert(i);
    out[i] = A;
  }

  rep(i, 0, N)if(!noin[i] && in[i].size() == 0) erase(i, out[i]);
  rep(i, 0, N)if(!noin[i]){
    queue<int> q;
    int s = i;
    q.push(s);
    while(out[s] != i){
      s = out[s];
      q.push(s);
    }

    cout << q.size() << endl;
    while(q.size()){
      cout << q.front() + 1 << ' ';
      q.pop();
    }
    cout << endl;
    return 0;
  }
}
