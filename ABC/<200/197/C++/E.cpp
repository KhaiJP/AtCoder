#include<iostream>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

// the problem is equivalent to the original if we consider an additional ball
// put on X = 0 whose color is N+1 and the goal is to collect all the balls in ascending order
// left_right_X[0(1)][C]: the left(rigth) most position of balls of colour C
ll N, left_right_X[2][200010], dp[2][200010], inf = 1e18;

int main(){
  cin >> N;
  rep(C, 1, N+2){
    left_right_X[0][C] =  inf;
    left_right_X[1][C] = -inf;
    dp[0][C] =  inf;
    dp[1][C] =  inf;
  }
  rep(i, 0, N){
    ll X, C; cin >> X >> C;
    left_right_X[0][C] = min(left_right_X[0][C], X);
    left_right_X[1][C] = max(left_right_X[1][C], X);
  }
  // addtional ball on X = 0 of colour N+1
  left_right_X[0][N+1] = left_right_X[1][N+1] = 0;
  
  rep(C, 1, N+2)if(left_right_X[0][C] < inf){
    rep(t, 0, 2)rep(s, 0, 2){
      ll start = left_right_X[s][C-1], terminal = left_right_X[t][C], opposite = left_right_X[1-t][C];
      ll travel_time = abs(start - opposite) + abs(opposite - terminal);
      dp[t][C] = min(dp[t][C], dp[s][C-1]+travel_time);
    }
  }else{
    rep(st, 0, 2){
      left_right_X[st][C] = left_right_X[st][C-1];
      dp[st][C] = dp[st][C-1];
    }
  }
  
  cout << dp[0][N+1] << endl;
  return 0;
}