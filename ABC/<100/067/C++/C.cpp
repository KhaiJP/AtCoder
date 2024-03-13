#include<iostream>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

ll N, a[200010], pfx[200010], total, answer = 1e18;

int main(){
  cin >> N;
  rep(i, 0, N) cin >> a[i];
  rep(i, 0, N) pfx[i+1] += pfx[i] + a[i];
  rep(i, 0, N) total += a[i];

  rep(i, 1, N) answer = min(answer, abs(pfx[i] - (total - pfx[i])));
  cout << answer << endl;
  return 0;
}