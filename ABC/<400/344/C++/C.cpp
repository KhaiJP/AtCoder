#include<iostream>
#include<set>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

ll Ns[3], As[3][110], Q;
set<ll> stock;

void dfs(ll i, ll s){
  if(i == 3){
    stock.insert(s);
    return ;
  }
  rep(j, 0, Ns[i]){
    dfs(i+1, s + As[i][j]);
  }
}

int main(){
  rep(i, 0, 3){
    cin >> Ns[i];
    rep(j, 0, Ns[i]) cin >> As[i][j];
  }
  dfs(0, 0);

  cin >> Q;
  while(Q--){
    ll X; cin >> X;
    cout << (stock.count(X) == 1 ? "Yes" : "No") << endl;
  }

  return 0;
}