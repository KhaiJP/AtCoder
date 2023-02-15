#include<iostream>
#include<iomanip>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define N_MAX 3010

// dp[ i ][ j ] : probability that j coins, up to 1 to i, show heads 
double dp[N_MAX][N_MAX];

int main(){
  int N; cin >> N;

  // 0 coin show head up to coin 0 is 1, or just for convenience 
  dp[0][0] = 1;
  rep(i, 1, N+1){
    double p; cin >> p;
    rep(j, 0, i+1){
      // when coin i show head
      dp[ i ][ j + 1 ] += dp[ i - 1][ j ] * p;
      // when coin i show tail
      dp[ i ][ j ] += dp[ i - 1 ][ j ] * (1-p); 
    }
  }
  
  double answer = 0;
  // more heads than tails <==> more than N/2 coins show heads
  rep(j, N/2+1, N+1) answer += dp[ N ][ j ];

  cout << fixed << setprecision(10) << answer << endl;
  return 0;
}