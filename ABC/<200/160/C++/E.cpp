#include<iostream>
#include<algorithm>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

ll aR[100010], aG[100010], aP[100010], pfxRG[200010], pfxP[100010], tmp[100010];

int main(){
  ll X, Y, A, B, C; cin >> X >> Y >> A >> B >> C;
  
  rep(i, 0, A) cin >> aR[i]; sort(aR, aR+A, greater<ll>());
  rep(i, 0, B) cin >> aG[i]; sort(aG, aG+B, greater<ll>());

  rep(i, 0, X) tmp[i] = aR[i];
  rep(i, 0, Y) tmp[X+i] = aG[i];
  ll Z = X + Y;
  sort(tmp, tmp+Z);

  rep(i, 0, C) cin >> aP[i]; sort(aP, aP+C, greater<ll>());
  rep(i, 0, min(C, Z))if(aP[i] > tmp[i]) tmp[i] = aP[i];

  ll answer = 0;
  rep(i, 0, Z) answer += tmp[i];
  cout << answer << endl;
  return 0;
}