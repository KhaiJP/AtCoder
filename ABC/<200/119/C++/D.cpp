#include<iostream>
#include<algorithm>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

ll s[100010], t[100010], A, B, Q;

int main(){
  cin >> A >> B >> Q;
  rep(i, 0, A) cin >> s[i];
  rep(i, 0, B) cin >> t[i];
  while(Q--){
    ll answer = 1e18, id_s, id_t;
    ll x; cin >> x;

    // Right side Shrine and Right side Temple
    id_s = lower_bound(s, s+A, x) - s;
    id_t = lower_bound(t, t+B, x) - t;
    if(0 <= id_s && id_s < A && 0 <= id_t && id_t < B){
      answer = min(answer, max(s[id_s], t[id_t])-x);
    }

    // Left side Shrine and Right side Temple
    id_s = upper_bound(s, s+A, x) - s; --id_s;
    id_t = lower_bound(t, t+B, x) - t;
    if(0 <= id_s && id_s < A && 0 <= id_t && id_t < B){
      answer = min(answer, min(2*t[id_t]-s[id_s]-x, t[id_t]+x-2*s[id_s]));
    }

    // Left side Shrine and Left side Temple
    id_s = upper_bound(s, s+A, x) - s; --id_s;
    id_t = upper_bound(t, t+B, x) - t; --id_t;
    if(0 <= id_s && id_s < A && 0 <= id_t && id_t < B){
      answer = min(answer, x - min(s[id_s], t[id_t]));
    }

    // Right side Shrine and Left side Temple
    id_s = lower_bound(s, s+A, x) - s;
    id_t = upper_bound(t, t+B, x) - t; --id_t;
    if(0 <= id_s && id_s < A && 0 <= id_t && id_t < B){
      answer = min(answer, min(2*s[id_s]-t[id_t]-x, s[id_s]+x-2*t[id_t]));
    }

    cout << answer << '\n';
  }
  return 0;
}