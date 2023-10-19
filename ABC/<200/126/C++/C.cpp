#include<iostream>
#include<iomanip>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

double dp[100010];

int main(){
  int N, K; cin >> N >> K;
  rep(i, 1, N+1) dp[min(i, K)] += (double)1/N;
  rep(i, 1, K) dp[min(2*i, K)] += dp[i] / 2;
  
  cout << fixed << setprecision(11) << dp[K] << endl;
  return 0;
}