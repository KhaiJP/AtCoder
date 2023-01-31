#include<iostream>
#include<vector>
#include<deque>
#include<unordered_map>
using namespace std;
using ll = int64_t;
using Edges = unordered_map<ll, vector<ll>>;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define fore(a, v) for(auto a : v)
#define N_MAX 200010
const ll MOD =  1000000000+7;

// dist[j] = the distance from 0 to j. counts[j] = number of paths reaching j with least edges
ll dist[N_MAX], counts[N_MAX];
const ll ll1 = 1;

int main(){
  ll N, M; cin >> N >> M;
  
  // set edges
  Edges E;
  rep(i, 0, M){
    ll A, B;   cin >> A >> B;   --A,   --B;
    E[A].push_back(B);   E[B].push_back(A);
  }

  // bfs preparations
  deque<ll> dq;
  dq.push_back(0);
  ++counts[0];
  rep(i, 1, N) dist[i] = MOD + ll1;

  // bfs
  while(!dq.empty()){
    ll &u = dq.front();   dq.pop_front();
    
    fore(v, E[u])if(dist[v] >= dist[u] + ll1){
      // if the minimum distance updates, then counts[v] is exactly the same as counts[u]
      if(dist[v] > dist[u] + ll1){
        dist[v] = dist[u] + ll1;
        counts[v] = counts[u];
        dq.push_back(v);
      }
      // if the distance is same, more counts[u] paths are possible 
      else counts[v] = ( counts[v] + counts[u] ) % MOD;
    }
  } // end bfs while
  
  cout << counts[N-1] << endl;
  return 0;
}