#include<iostream>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint998244353;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define rrep(i, s, t) for(int i = (s); i >= (t); --i)

mint dp[110][110][2];

int main(){
  int N, A, B, P, Q; cin >> N >> A >> B >> P >> Q;

  rep(i, 1, N)rep(k, 0, 2){
    dp[N][i][k] = 1;
    dp[i][N][k] = 0;
  }

  rrep(i, N-1, 0)rrep(j, N-1, 0){
    rep(k, 1, P+1) dp[i][j][0] += dp[min(i+k, N)][j][1];
    dp[i][j][0] /= P;

    rep(k, 1, Q+1) dp[i][j][1] += dp[i][min(j+k, N)][0];
    dp[i][j][1] /= Q;
  }

  cout << dp[A][B][0].val() << endl;
  return 0;
}