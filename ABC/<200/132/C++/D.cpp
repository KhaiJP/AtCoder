#include<iostream>
#include<atcoder/all>
using namespace std;
using ll = int64_t;
using mint = atcoder::modint1000000007;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define MAX 2010

ll N, K;
mint fac[MAX], finv[MAX], inv[MAX];
void nCk_init(){
  const ll mod = mint::mod();
  fac[0]  = fac[1]  = 1;
  finv[0] = finv[1] = 1;
  inv[1]  = 1;
  rep(i, 2, MAX){
    fac[i]  = fac[i-1] * i;
    inv[i]  = mod - inv[mod%i] * (mod / i);
    finv[i] = finv[i-1] * inv[i];
  }
}

mint nCk(ll n, ll k){
  if(n < k) return 0;
  if(n < 0 || k < 0) return 0;
  return fac[n] * finv[k] * finv[n-k];
}

mint nHk(ll n, ll k){
  return nCk(n+k-1, k);
}

int main(){
  nCk_init();

  cin >> N >> K;

  rep(k, 1, K+1){
    ll r = N - K - (k-1);
    ll b = K - k;
    mint ans = nHk(k, b) * nHk(k+1, r);
    cout << ans.val() << endl;
  }
  return 0;
}