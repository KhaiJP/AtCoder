#include<iostream>
#include<vector>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

ll answer = 0;
ll N, X;

vector<vector<ll>> A;

void dfs(ll id, ll prod){
  if ( id == N ){
    if( prod == X ) ++answer;
    return ;
}
  for(ll c : A[id])if(prod <= X/c) dfs(id+1, prod*c);
}

int main(){
  cin >> N >> X;
  A.resize(N);
  rep(i, 0, N){
    ll L; cin >> L;
    A[i].resize(L);
    rep(j, 0, L) cin >> A[i][j];
  }
  dfs(0, 1);

  cout << answer << endl;
  return 0;
}