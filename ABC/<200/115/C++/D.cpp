#include<iostream>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

// whole # of patties in the buger of level L
ll whole_patties(ll L){
  ll ret = 1;
  ret = (ret << (L+1)) - 1;
  return ret;
}

// whole length of the buger of lovel L
ll whole_length(ll L){
  ll ret = 1;
  ret = (ret << (L+2)) - 3;
  return ret;
}

ll f(ll L, ll x){
  ll len = whole_length(L);
  if(L == 0) return 1;
  // buger of level L, aL, consists of " B  aL-1  P  aL-1  B "
  if(x == 1) return 0;
  if(x <= len/2)   return f(L-1, x-1);
  if(x == len/2+1) return whole_patties(L-1) + 1;
  if(x <= len-1)   return whole_patties(L-1) + 1 + f(L-1, x-len/2-1);
  if(x == len) return 2 * whole_patties(L-1) + 1;
}

int main(){
  ll N, X; cin >> N >> X;
  cout << f(N, X) << endl;
  return 0;
}