#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
using ll = int64_t;
using P  = pair<ll, ll>; 
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

set<P> S;
ll N, M, L, answer;
P a[100010], b[100010];

int main(){
  cin >> N >> M >> L;
  rep(i, 0, N){
    ll x; cin >> x;
    a[i] = {x, i};
  }sort(a, a+N, greater<P>());
  rep(i, 0, M){
    ll x; cin >> x;
    b[i] = {x, i};
  }sort(b, b+M, greater<P>());

  rep(i, 0, L){
    ll c, d; cin >> c >> d;
    --c, --d;
    S.insert({c, d});
  }

  // greedy
  rep(i, 0, N){
    ll a_val = a[i].first, a_idx = a[i].second;
    rep(j, 0, M){
      ll b_val = b[j].first, b_idx = b[j].second;
      if(S.count({a_idx, b_idx}) == 0){
        answer = max(answer, a_val + b_val);
        break;
      }
    }
  }

  cout << answer << endl;
  return 0;
}