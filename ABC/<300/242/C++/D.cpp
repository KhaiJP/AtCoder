#include<iostream>
#include<string>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

string S;

char g(char c, ll t){
  return char( 'A' + (c - 'A' + t) % 3 );
}

char f(ll t, ll k){
  if(t == 0) return S[k];
  if(k == 0) return g(S[0], t);
  return g( f( t - 1, k/2 ),  k % 2 + 1  );
}

int main(){
  cin >> S;
  int Q; cin >> Q;

  while(Q--){
    ll t, k; cin >> t >> k;
    cout << f(t, k-1) << endl;
  }
  return 0;
}