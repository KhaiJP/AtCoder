#include<iostream>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

ll pfx[200010];

int main(){
  ll N, W; cin >> N >> W;
  rep(i, 0, N){
    ll S, T, P; cin >> S >> T >> P;
    pfx[S] += P, pfx[T] -= P;
  }rep(i, 1, 200005) pfx[i] += pfx[i-1];

  rep(i, 0, 200005)if(pfx[i] > W){
    cout << "No" << endl;
    return 0;
  }

  cout << "Yes" << endl;
  return 0;
}