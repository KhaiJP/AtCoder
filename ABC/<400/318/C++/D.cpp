#include<iostream>
#include<vector>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

vector<pair<ll, ll>> P;
ll D[20][20], N, answer;
bool used[20];

void dfs(){
  if(P.size() == N/2){
    ll tmp = 0;
    for(auto p : P) tmp += D[p.first][p.second];
    answer = max(answer, tmp);
    return ;
  }

  ll u;
  rep(i, 1, N)if(!used[i]){
    u = i;
    used[u] = true;
    break;
  }

  rep(v, u+1, N+1)if(!used[v]){
    used[v] = true;
    P.push_back({u, v});
    dfs();
    P.pop_back();
    used[v] = false;
  }
  used[u] = false;
  return ;
}

int main(){
  cin >> N;
  rep(i, 1, N)rep(j, i+1, N+1) cin >> D[i][j];

  if(N & 1)rep(i, 1, N+1){
    used[i] = true;
    dfs();
    used[i] = false;
  }
  else{
    dfs();
  }

  cout << answer << endl;
  return 0;
}