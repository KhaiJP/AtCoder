#include<iostream>
#include<string>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define fore(a, v) for(auto a : v)

const int MOD =  1000000000+7;
int dp[2010];

int main(){
  int S; cin >> S;
  dp[0] = 1;
  dp[3] = 1;
  rep(i, 4, S+1){
    rep(j, 0, i-2){
      dp[i] = (dp[i] + dp[j]) % MOD;
    }
  }
  cout << dp[S] << endl;
  return 0;
}