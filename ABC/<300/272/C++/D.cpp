#include<iostream>
#include<vector>
#include<set>
#include<deque>
#define rep(i,s,t) for(int i=(s); i<(t); ++i)
using namespace std;
typedef pair<int, int> P;

int main(){
  int N, M; cin >> N >> M;
  // Ps = {(dx, dy) | dx,dy in Z st dx^2 + dy^2 = M}
  set<P> Ps;
  for(int dx=0; dx*dx<=M; ++dx){
    for(int dy=0; dx*dx+dy*dy <=M; ++dy){
      if(dx*dx+dy*dy == M){
        Ps.insert(P ( dx,  dy));
        Ps.insert(P ( dx, -dy));
        Ps.insert(P (-dx,  dy));
        Ps.insert(P (-dx, -dy));
      }
    }
  }

  // queue for bfs
  deque<P> dq;
  dq.push_back(P(1,1));
  // distance array
  vector dist(N+1, vector<int>(N+1, 1e9));
  dist[1][1] = 0;
  // bfs
  while (!dq.empty()){
    int u, v;
    u = dq.front().first, v = dq.front().second; dq.pop_front();
    for(auto const p : Ps){
      int u_ = u + p.first, v_ = v + p.second;  
      if(1<=u_ && u_<=N && 1<=v_ && v_<=N) if(dist[u][v]+1 < dist[u_][v_]){
        dist[u_][v_] = dist[u][v]+1;
        dq.push_back(P(u_,v_));
      }
    }
  }
  rep(i,1,N+1){
    rep(j,1,N+1) cout << (dist[i][j]==1e9 ? -1 : dist[i][j]) << ' ';
    cout << '\n';
  }
  return 0;
}
