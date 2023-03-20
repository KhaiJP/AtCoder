#include<iostream>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

pair<ll, ll> l1[100010], l2[100010];

int main(){
  ll L, N1, N2; cin >> L >> N1 >> N2;
  rep(i, 0, N1){
    ll u, l; cin >> u >> l;
    l1[i] = {u, l};
  }
  rep(i, 0, N2){
    ll u, l; cin >> u >> l;
    l2[i] = {u, l};
  }

  ll answer = 0;
  int id1 = 0, id2 = 0;
  while(id1 != N1 || id2 != N2){

    if( id1 < N1 && l1[id1].second < l2[id2].second || id2 == N2){
      if( l1[id1].first == l2[id2].first ) answer += l1[id1].second;
      l2[id2].second -= l1[id1].second;
      ++id1;
    }

    else if( id2 < N2 && l2[id2].second < l1[id1].second || id1 == N1){
      if( l2[id2].first == l1[id1].first ) answer += l2[id2].second;
      l1[id1].second -= l2[id2].second;
      ++id2;
    }
    
    else{
      if( l1[id1].first == l2[id2].first ) answer += l1[id1].second;
      ++id1, ++id2;
    }
  }

  cout << answer << endl;
  return 0;
}
