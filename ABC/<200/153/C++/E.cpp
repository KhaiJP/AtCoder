#include<iostream>
using namespace std;
typedef int64_t ll;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int dp[1001][10001];
int H, N;

int main(){
  cin >> H >> N;
  rep(n,0,N+1)rep(h,0,H+1) dp[n][h] = 1000000000+7;
  dp[0][0] = 0;
  rep(n,0,N){
    int A, B; cin >> A >> B;
    rep(h,0,H+1){
      if(dp[n][h] == 1000000000+7) continue;
      dp[n+1][h] = min(dp[n+1][h], dp[n][h]);
      dp[n][min(h+A,H)] = min(dp[n][min(h+A,H)], dp[n][h]+B); 
    }
  }
  cout << dp[N][H] << endl;
  return 0;
}