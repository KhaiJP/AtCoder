#include<iostream>
#include<algorithm>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define rrep(i, s, t) for(int i = (s); i >= (t); --i)
#define yes "YES"
#define noo "NO"

bool dp[110][310];

int main(){
  int N; cin >> N;
  int NG[3]; rep(i,0,3) cin >> NG[i];
  sort(NG, NG+3);

  if(find(NG, NG+3, N) == NG+3) dp[0][N] = true;
  rep(n,0,100)rrep(m,N,1){
    if(!dp[n][m]) continue;
    rep(i,1,4){
      if(m-i >= 0 && find(NG, NG+3, m-i) == NG+3){
        dp[n+1][m-i] = true;
      }
    }
  }
  bool isOK = false;
  rep(i,0,101) isOK = isOK || dp[i][0];
  cout << (isOK ? yes : noo) << endl;
  return 0;
}