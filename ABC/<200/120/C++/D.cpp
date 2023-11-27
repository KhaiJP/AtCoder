#include<iostream>
#include<vector>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

ll N, M, answer[200010], A[100010], B[100010], parent[200010];
vector<ll> G[200010];

ll leader_of(ll a){
  if(parent[a] == a) return a;
  return parent[a] = leader_of(parent[a]);
}

bool same(ll a, ll b){
  return leader_of(a) == leader_of(b);
}

bool merge(ll a, ll b){
  a = leader_of(a), b = leader_of(b);
  if(a == b) return false;

  if(G[a].size() < G[b].size()) swap(a, b);
  parent[b] = a;
  for(auto x : G[b]) G[a].push_back(x);
  G[b].clear();
  return false;
}

int main(){
  cin >> N >> M;
  rep(i, 0, M) cin >> A[i] >> B[i];
  rep(i, 1, N+1){
    parent[i] = i;
    G[i] = {i};
  }

  answer[M] = N * (N-1) / 2;
  rep(i, 0, M){
    ll delta = 0;
    ll id = M-1-i;
    ll a = A[id], b = B[id];
    if(!same(a, b)){
      a = leader_of(a), b = leader_of(b);
      ll sa = G[a].size(), sb = G[b].size();
      delta = sa * sb;
      merge(a, b);
    }
    answer[id] = answer[id+1] - delta;
  }

  rep(i, 1, M+1) cout << answer[i] << endl;
  return 0;
}