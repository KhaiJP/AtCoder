#include<iostream>
#include<vector>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

// reference : https://drken1215.hatenablog.com/entry/2021/10/08/231200
const ll MOD = 1000000007;
const ll LOG = 62;
const ll ll1 = 1;
ll c[10];
ll N, B, K;

vector<ll> update(const vector<ll> &dpi, const vector<ll> &dpj, ll ten_j){
  vector<ll> res(B, 0);
  rep(p, 0, B)rep(q, 0, B){
    res[(p * ten_j + q) % B] += dpi[p] * dpj[q];
    res[(p * ten_j + q) % B] %= MOD;
  }
  return res;
}


int main(){
  cin >> N >> B >> K;
  rep(k, 0, K) cin >> c[k];

  vector<ll> ten(LOG, 10);
  rep(i, 1, LOG) ten[i] = (ten[i-1] * ten[i-1]) % B;

  vector doubling(LOG, vector<ll>(B, 0));
  rep(k, 0, K) doubling[0][c[k] % B] += 1;

  rep(i, 1, LOG) doubling[i] = update(doubling[i-1], doubling[i-1], ten[i-1]);

  vector<ll> res(B, 0);
  res[0] = 1;
  rep(i, 0, LOG)if(N & (ll1 << i)) res = update(res, doubling[i], ten[i]);

  cout << res[0] << endl;
  return 0;
}