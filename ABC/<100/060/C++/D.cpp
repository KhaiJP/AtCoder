#include<iostream>
#include<map>
#include<set>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

ll N, W, pfx[5][110], weight[5], answer;
map<ll, multiset<ll>> m;


int main(){
  cin >> N >> W;
  rep(i, 0, N){
    ll w, v; cin >> w >> v;
    m[w].insert(-v);
  }
  rep(i, 0, 4){
    ll w = (m.begin()->first) + i;
    weight[i] = w;
    ll j = 1;
    for(auto itr = m[w].begin(); itr != m[w].end(); ++itr){
      ll delta = -(*itr);
      pfx[i][j] = pfx[i][j-1] + delta;
      ++j;
    }
  }
  rep(a, 0, 101)rep(b, 0, 101)rep(c, 0, 101)rep(d, 0, 101){
    ll _W = a*weight[0] + b*weight[1] + c*weight[2] + d*weight[3];
    if(_W > W) continue;
    answer = max(answer, pfx[0][a] + pfx[1][b] + pfx[2][c] + pfx[3][d]);
  }

  cout << answer << endl;
  return 0;
}