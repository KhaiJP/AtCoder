#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)
#define NOT_USED false

ll N, M, K, W[100], inf = 1e18, answer = 1e18;
pair<ll, ll> p[100];
bool visited[10];
vector<bool> V;
map<pair<ll,ll>, ll> m;

ll dfs(ll me=0){
  ll weights_sum = 0;
  visited[me] = true;
  rep(child, 0, N)if(!visited[child] && m.count({me,child})){
    ll edge_index = m[{me, child}];
    if(V[edge_index] == NOT_USED) continue;
    weights_sum += dfs(child) + W[edge_index];
    weights_sum %= K;
  }
  return weights_sum;
}

ll get_weights_sum(){
  rep(i, 0, N) visited[i] = false;
  ll weigths_sum = dfs();
  bool all_visited = true;
  rep(i, 0, N) all_visited = all_visited && visited[i];
  return (all_visited ? weigths_sum : inf);
}

int main(){
  cin >> N >> M >> K;
  rep(i, 0, M){
    ll u, v, w; cin >> u >> v >> w;
    --u, --v, w %= K;
    p[i] = {u, v};
    W[i] = w;
    m[{u, v}] = m[{v, u}] = i;
  }

  rep(i, 0, M) V.push_back(true);
  rep(i, 0, M-N+1) V[i] = false;
  do{
    answer = min(answer, get_weights_sum());
  }while(next_permutation(V.begin(), V.end()));

  cout << answer << endl;
  return 0;
}