#include<iostream>
#include<algorithm>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

ll N, M, answer = 1e18, H[200010], W[200010];
ll pfx1[200010], pfx2[200010];

int main(){
  cin >> N >> M;
  rep(i, 0, N) cin >> H[i]; sort(H, H+N);
  rep(i, 0, M) cin >> W[i];
  for(int i = 0; i<N; i+=2) pfx1[i/2+1] = pfx1[i/2]   + H[i+1]-H[i];
  for(int i=N-2; i>0; i-=2) pfx2[i/2]   = pfx2[i/2+1] + H[i+1]-H[i];
  rep(i, 0, M){
    ll w = W[i];
    ll id = lower_bound(H, H+N, w) - H;
    if(id&1) id -= 1;
    answer = min(answer, pfx1[id/2] + pfx2[id/2] + abs(H[id]-w));
  }

  cout << answer << endl;
  return 0;
}