#include<iostream>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

ll dp[1010][1010];

int main(){
  int N; cin >> N;
  
  int t = 1, a = 1;
  dp[t][a] = 2;

  rep(i, 0, N){
    int T, A; cin >> T >> A;
    ll q  = dp[t][a] / (t + a);
    ll vT = q * t, vA = q * a;
    ll n  = max((vT + T -1) / T, (vA + A - 1) / A);
    dp[T][A] = n * (T + A);
    t = T, a = A;  
  }
  
  cout << dp[t][a] << endl;
  return 0;
}