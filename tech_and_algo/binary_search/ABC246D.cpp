#include<iostream>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

ll f(ll a, ll b){
  return a*a*a + a*a*b + a*b*b + b*b*b;
}

int main(){
  ll N; cin >> N;
  ll answer =9e18;

  rep(a, 0, 1000001){
    if(f(a,0) > N) break;
    ll l = -1, r = 1000000;
    while(l+1 < r){
      ll b = (l + r) / 2;
      if(f(a, b) >= N) r = b;
      else l = b;
    }
    answer = min(answer, f(a,r));
  }

  cout << answer << endl;
  return 0;
}