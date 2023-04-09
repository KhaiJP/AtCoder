#include<iostream>
#include<queue>
#include<set>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

ll A[14], N, K;
priority_queue<ll> q;
set<ll> monitor;

ll Dijkstra_ish(){
  ll pay = -q.top(); q.pop();
  if(monitor.count(pay) == 1) return Dijkstra_ish();
  
  monitor.insert(pay);
  if(monitor.size() == K) return pay;

  rep(i, 0, N) q.push( -( pay + A[i] ) );
  return Dijkstra_ish();
}

int main(){
  cin >> N >> K;
  rep(i, 0, N){
    cin >> A[i];
    q.push(-A[i]);
  }

  cout << Dijkstra_ish() << endl;
  return 0;
}