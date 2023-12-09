#include<iostream>
#include<atcoder/all>
using namespace std;
using ll = int64_t;
using mint = atcoder::modint998244353;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)
#define rrep(i, s, t) for(ll i = (s); i >= (t); ++i)

mint p = 1, dp[10010], answer;
ll N, X, T[1010];

int main(){
  cin >> N >> X;
  rep(i, 0, N) cin >> T[i];
  p /= N;

  dp[0] = 1;
  rep(t, 0, X)rep(i, 0, N)if(t + T[i] <= X){
    dp[t+T[i]] += p * dp[t];
  }
  rep(t, 0, X+1)if(t + T[0] > X){
    answer += p * dp[t];
  }
  cout << answer.val() << endl;
  return 0;
}