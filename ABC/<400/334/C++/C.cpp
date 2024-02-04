#include<iostream>
#include<algorithm>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)
#define rrep(i, s, t) for(ll i = (s); i >= (t); --i)

ll N, K, sock[200010], rest[200010], n;
ll answer, pfxL[200010], pfxR[200010];

int main(){
  cin >> N >> K;
  rep(i, 1, N+1) sock[i] = 2;
  rep(i, 0, K){
    ll A; cin >> A;
    --sock[A];
  }
  rep(i, 1, N+1)if(sock[i] == 1){
    rest[n] = i;
    ++n;
  }sort(rest, rest + n);

  if(n%2 == 0){
    rep(i, 0, n){
      answer += rest[i+1] - rest[i];
      ++i;
    }
    cout << answer << endl;
    return 0;
  }

  rep(i, 1, n){
    if(i&1) pfxL[i] = pfxL[i-1];
    else    pfxL[i] = pfxL[i-1] + rest[i-1] - rest[i-2];
  }
  rrep(i, n-2, 0){
    if(i&1) pfxR[i] = pfxR[i+1];
    else    pfxR[i] = pfxR[i+1] + rest[i+2] - rest[i+1];
  }
  answer = 1e18;
  rep(i, 0, n){
    ll tmp = pfxL[i] + pfxR[i];
    if(i&1) tmp += rest[i+1] - rest[i-1];
    answer = min(answer, tmp);
  }

  cout << answer << endl;
  return 0;
}