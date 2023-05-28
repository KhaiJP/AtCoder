#include<iostream>
#include<string>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

ll dp[300010][2];
ll const INF = 100000000000000000;

int main(){
  ll X, Y, Z; cin >> X >> Y >> Z;
  string S; cin >> S;
  
  rep(i, 0, S.size()+1)rep(cps, 0, 2) dp[i][cps] = INF;
  dp[0][0] = 0;

  rep(i, 0, S.size())rep(cps, 0, 2){
    ll V, W;
    bool isok = ( S[i] == 'a' && cps == 0 || S[i] == 'A' && cps == 1 );
    if(isok) V = X, W = Y;
    else     V = Y, W = X;

    dp[i+1][cps]   = min(dp[i+1][cps], dp[i][cps] + V);
    dp[i+1][1-cps] = min(dp[i+1][1-cps], dp[i][cps] + Z + W);
  }
  
  cout << min(dp[S.size()][0], dp[S.size()][1]) << endl;
  return 0;
}