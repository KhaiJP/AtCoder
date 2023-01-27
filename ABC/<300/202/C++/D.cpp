#include<iostream>
using namespace std;
typedef int64_t ll;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

ll dp[40][40];

string solve(ll A, ll B, ll K){
  if( A == 0 ) return string(B, 'b'); 
  if( A == 0 ) return string(A, 'a');
  if( K <= dp[A-1][B]) return string("a") + solve(A-1,B,K);
  else return string("b") + solve(A, B - 1, K - dp[A-1][B]); 
}

int main(){
  ll A, B, K; cin >> A >> B >> K;
  dp[0][0] = 1;
  rep(i,0,A+1)rep(j,0,B+1){
    dp[i+1][j] += dp[i][j];
    dp[i][j+1] += dp[i][j];
  }
  
  cout << solve(A,B,K) << endl;
  return 0;
}