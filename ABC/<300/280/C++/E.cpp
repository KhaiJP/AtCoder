#include<iostream>
#include<atcoder/all>
using namespace std;
using mint = atcoder::modint998244353;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

mint dp[200010], P, Q;
int N, t;

int main(){
  cin >> N >> t;
  P = mint(t) / 100;
  Q = mint(1) - P;
  rep(i, 1, N+1){
    dp[i] = dp[max(i-2, 0)] * P + dp[i-1] * Q + 1;
  }

  cout << dp[N].val() << endl;
}