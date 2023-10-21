#include<iostream>
#include<atcoder/all>
using namespace std;
using mint = atcoder::modint1000000007;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

mint dp[2020];

int main(){
  int S; cin >> S;
  rep(i, 3, 2001){
    dp[i] += 1;
    rep(j, i+3, 2001) dp[j] += dp[i];
  }

  cout << dp[S].val() << endl;
  return 0;
}