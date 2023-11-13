#include<iostream>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

ll N, Q, parent[200010], weight[200010];

ll leader_of(ll a){
  if(parent[a] == a) return a;
  ll p = leader_of(parent[a]);
  weight[a] += weight[parent[a]];
  parent[a] = p;
  return p;
}

bool merge(ll a, ll b, ll d){
  ll leader_a = leader_of(a), leader_b = leader_of(b);
  if(leader_a == leader_b) return weight[a] == weight[b] + d;
  parent[leader_a] = leader_b;
  weight[leader_a] = weight[b] - weight[a] + d;
  return true;
}

int main(){
  cin >> N >> Q;
  rep(i, 1, N+1) parent[i] = i, weight[i] = 0;
  rep(i, 1, Q+1){
    ll a, b, d; cin >> a >> b >> d;
    if(merge(a, b, d)) cout << i << ' ';
  }
  cout << endl;
  return 0;
}