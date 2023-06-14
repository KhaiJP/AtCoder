#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

vector<int> E[2010];
int dist[2010][2010];

int main(){
  int N, X, Y; cin >> N >> X >> Y; --X, --Y;
  rep(i, 0, N-1) E[i].push_back(i+1), E[i+1].push_back(i);
  E[X].push_back(Y), E[Y].push_back(X);

  rep(u, 0, N)rep(v, 0, N)if(u != v) dist[u][v] = 1e9;
  map<int, int> ans;

  rep(u, 0, N){
    queue<int> q; q.push(u);
    while(q.size()){
      int pre = q.front(); q.pop();
      for(auto v : E[pre])if(dist[u][v] == 1e9){
        dist[u][v] = dist[u][pre] + 1;
        q.push(v);
      }
    }
    rep(v, 0, N)if(v != u) ++ans[dist[u][v]];
  }

  rep(k, 1, N) cout << ans[k]/2 << endl;
  return 0;
}