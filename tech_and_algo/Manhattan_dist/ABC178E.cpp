#include<iostream>
#include<algorithm>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

ll Z[200010], W[200010], cand[4];

int main(){
  ll N; cin >> N;
  rep(i, 0, N){
    ll x, y; cin >> x >> y;
    Z[i] = x + y;
    W[i] = x - y ;
  }sort(Z, Z+N), sort(W, W+N);

  ll answer = 0;
  answer = max(answer, Z[N-1] - Z[0]);
  answer = max(answer, W[N-1] - W[0]);
  
  cout << answer << endl;
  return 0;
}