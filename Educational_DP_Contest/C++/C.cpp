#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define N_MAX 100010

// dp[j][l] : maximum point in day j choosing l( = 0 -> a, = 1 -> b, = 2 -> c)
int dp[N_MAX][3], points[N_MAX][3];

int main(){
  int N; cin >> N;
  rep(i, 1, N+1) cin >> points[i][0] >> points[i][1] >> points[i][2];
  rep(l, 0, 3) dp[1][l] = points[1][l];

  // cl : current letter,   nl : next letter
  rep(i, 1, N)rep(cl, 0, 3)rep(nl, 0, 3){
    if(cl == nl) continue;
    dp[i+1][nl] = max(dp[i+1][nl], dp[i][cl] +  points[i+1][nl] );
  }

  int answer = 0;
  rep(l, 0, 3) answer = max(answer, dp[N][l]);
  
  cout << answer << endl;
  return 0;
}