#include<iostream>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

bool A[1000010];
ll dp[1000010][2];

int main(){
  int N; cin >> N;
  rep(i, 0, N){
    char c; cin >> c;
    A[i] = c == '1';
  }

  rep(i, 0, N){
    dp[i+1][!(A[i] & 0)] += dp[i][0];
    dp[i+1][!(A[i] & 1)] += dp[i][1];
    dp[i+1][  A[i]     ] += 1;
  }

  ll answer = 0;
  rep(i, 0, N+1) answer += dp[i][1];
  cout << answer << endl;
  return 0;
}