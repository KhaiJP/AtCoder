#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  int N, Q; cin >> N >> Q;
  unordered_map<int, vector<int>> dealer;
  rep(i,1,N+1){
    int a; cin >> a;
    dealer[a].push_back(i);
  }
  rep(q,0,Q){
    int x, k; cin >> x >> k;
    if(dealer.count(x) != 1 || dealer[x].size() < k) cout << -1 << '\n';
    else cout << dealer[x][k-1] << '\n';
  }
  return 0;
}