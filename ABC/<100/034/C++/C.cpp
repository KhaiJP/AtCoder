#include <iostream>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

// ref https://drken1215.hatenablog.com/entry/2018/06/08/210000
const int MAX = 510000;
const int MOD = 1000000007;
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
ll nCk(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
  	ll W, H; cin >> W >> H;
    // 前処理
    COMinit();

    // 計算例
    cout << nCk(W+H-2, W-1) << endl;
}