#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int A[110], dp[10010], N, K;

int main(){
  cin >> N >> K;
  rep(k, 0, K) cin >> A[k];
  
  rep(i, 0, N+1)rep(k, 0, K){
    if(A[k] > i) break;
    dp[i] = max(dp[i], i - dp[i - A[k]]);
  }

  cout << dp[N] << endl;
  return 0;
}