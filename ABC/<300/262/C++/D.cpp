#include<iostream>
#include<atcoder/all>
using namespace std;
using mint = atcoder::modint998244353;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int N, a[110];
mint dp[110][110][110][110], answer;

int main(){
  cin >> N;
  rep(i, 0, N) cin >> a[i];

  rep(i, 1, N+1) dp[i][0][0][0] = 1;
  rep(i, 1, N+1)rep(j, 0, N)rep(k, 0, i+1)rep(l, 0, i){
    dp[i][j+1][k][l] += dp[i][j][k][l];
    if(k == i) continue;
    dp[i][j+1][k+1][(l+a[j])%i] += dp[i][j][k][l];
  }
  rep(i, 1, N+1) answer += dp[i][N][i][0];
  cout << answer.val() << endl;
  return 0;
}