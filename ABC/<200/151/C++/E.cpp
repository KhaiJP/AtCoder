#include<iostream>
#include<algorithm>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

ll A[100010];

// ref https://drken1215.hatenablog.com/entry/2018/06/08/210000
const ll MAX = 510000;
const ll MOD = 1000000007;
ll fac[MAX], finv[MAX], inv[MAX];
// preprocessing
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    rep(i, 2, MAX){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
// combination
ll nCk(ll n, ll k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main(){
  COMinit();
  int N, K; cin >> N >> K;
  rep(i, 0, N) cin >> A[i];
  sort(A, A+N);

  ll maxX = 0;
  rep(i, K-1, N) maxX = (maxX + A[i] * nCk(i, K-1)) % MOD;

  ll minX = 0;
  sort(A, A+N, greater<ll>());
  rep(i, K-1, N) minX = (minX + A[i] * nCk(i, K-1)) % MOD;

  cout << (maxX - minX) % MOD << endl;
  return 0;
}