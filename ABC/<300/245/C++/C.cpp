#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define rrep(i, s, t) for(int i = (s); i >= (t); --i)
#define yes "Yes"
#define noo "No"

bool dp[200010][2];
int ab[200010][2];

int main(){
  int n, k; cin >> n >> k;
  rep(i, 1, n+1) cin >> ab[i][0];
  rep(i, 1, n+1) cin >> ab[i][1];
  
  dp[n][0] = true, dp[n][1] = true;
  rrep(i, n-1, 1)rep(pre, 0, 2)rep(nxt, 0, 2){
    dp[i][nxt] = dp[i][nxt] || (dp[i+1][pre] && abs(ab[i][nxt] - ab[i+1][pre]) <= k);
  }

  cout << (dp[1][0] || dp[1][1] ? yes : noo) << endl;
  return 0;
}