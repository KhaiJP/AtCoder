#include<iostream>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

ll N, A, B, C, h[100010];

bool is_ok(ll n){
  ll cnt = 0;
  rep(i, 0, N){
    cnt += (max(h[i]-n*B, (ll)0) + C - 1) / C;
  }
  
  return cnt <= n;
}

int main(){
  cin >> N >> A >> B;
  C = A - B;
  rep(i, 0, N) cin >> h[i];

  ll ok = 1e9, ng = 0;
  while(abs(ok-ng) > 1){
    ll mid = (ok + ng) / 2;
    if(is_ok(mid)) ok = mid;
    else           ng = mid;
  }

  cout << ok << endl;
  return 0;
}