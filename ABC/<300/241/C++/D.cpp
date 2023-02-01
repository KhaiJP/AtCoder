#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)
#define N_MAX 3001

int main(){
  multiset<ll> A;
  int Q; cin >> Q;

  rep(q,0,Q){
    int q_head; cin >> q_head;

    if ( q_head == 1 ){
      ll x; cin >> x;
      A.insert(x);
    }
    
    if ( q_head == 2 ){
      ll x, k; cin >> x >> k;
      bool flag = true;
      // upper_bound(A.begin(), A.end(), x) works f***ing slowly
      auto itr = A.upper_bound(x);
      rep(i, 0, k){
        if ( itr == A.begin()){
          flag = false;
          break;
        }
        --itr;
      }
      cout << (flag ? *itr : -1) << '\n';
    }

    if ( q_head == 3 ){
      ll x, k; cin >> x >> k;
      bool flag = true;
      // lower_bound(A.begin(), A.end(), x) works f***ing slowly
      auto itr = A.lower_bound(x);
      rep(i, 0, k-1){
        if ( itr == A.end() ){
          flag = false;
          break;;
        }
        ++itr;
      }
      if ( itr == A.end() ) flag = false;
      cout << (flag ? *itr : -1) << '\n';
    }

  }

}