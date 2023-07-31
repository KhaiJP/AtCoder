#include<iostream>
#include<set>
#include<map>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

const ll  N = 1 << 20;

int main(){
  int Q; cin >> Q;
  set<ll> S;
  rep(i, 0, N) S.insert(i);
  map<ll, ll> M;

  while(Q--){
    ll t, x; cin >> t >> x;
    ll h = x % N;
    if(t == 1){
      auto itr = S.lower_bound(h);
      if(itr == S.end()) itr = S.begin();
      
      M[*itr] = x;
      S.erase(itr);
    }

    if(t == 2){
      cout << (M.count(h) ? M[h] : -1) << endl;
    }
  }

  return 0;
}