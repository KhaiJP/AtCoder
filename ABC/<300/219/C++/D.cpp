#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int dp[330][330][330];
int A[330], B[330];

int main(){
  int N, X, Y; cin >> N >> X >> Y;
  rep(i, 0, N) cin >> A[i] >> B[i];

  rep(i, 0, N + 1)rep(oct, 0, X+1)rep(fish, 0, Y+1) dp[i][oct][fish] = 1000;
  dp[0][0][0] = 0;

  rep(i, 0, N)rep(oct, 0, X+1)rep(fish, 0, Y+1)if(dp[i][oct][fish] < 1000){
    // not choose i-th lunchbox
    dp[i+1][oct][fish] = min(dp[i+1][oct][fish], dp[i][oct][fish]);

    // choose i-th lunchbox
    int nxt_oct = min(oct + A[i], X),  nxt_fish = min(fish + B[i], Y);
    dp[i+1][nxt_oct][nxt_fish] = min(dp[i+1][nxt_oct][nxt_fish], dp[i][oct][fish] + 1);
  }
  
  cout << (dp[N][X][Y] < 1000 ? dp[N][X][Y] : -1) << endl;
  return 0;
}