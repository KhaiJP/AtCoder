#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int a[100010], dp[100010];
int const INF = 1000000007;

int main(){
  int N; cin >> N;
  rep(i, 0, N){
    cin >> a[i];
    dp[i] = INF;
  }

  dp[0] = 0;
  rep(i, 0, N-1){
    dp[i+1] = min(dp[i+1], dp[i] + abs(a[i] - a[i+1]));
    if(i == N - 2) continue;
    dp[i+2] = min(dp[i+2], dp[i] + abs(a[i] - a[i+2]));
  }

  cout << dp[N-1] << endl;
  return 0;
}