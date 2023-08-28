#include<iostream>
#include<set>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

multiset<ll> A;

int main(){
  rep(i, 0, 5) A.insert(-1);
  rep(i, 0, 5) A.insert(2e18);
  
  ll Q; cin >> Q;
  while(Q--){
    ll c; cin >> c;
    if(c == 1){
      ll x; cin >> x;
      A.insert(x);
    }
    
    if(c == 2){
      ll x, k; cin >> x >> k;
      auto itr = A.upper_bound(x);
      rep(i, 0, k) --itr;
      ll y = *itr;
      cout << (y != 2e18 ? y : -1) << endl;
    }

    if(c == 3){
      ll x, k; cin >> x >> k;
      auto itr = A.lower_bound(x);
      rep(i, 1, k) ++itr;
      ll y = *itr;
      cout << (y != 2e18 ? y : -1) << endl;
    }
  }
}