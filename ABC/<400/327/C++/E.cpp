#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define chmax(a, b) a = max(a, b)


double dp[5010][5010], q=0.9, sq[5010], answer=-1e15;
int N, P[5010];

int main(){
  cin >> N;
  rep(i, 0, N) cin >> P[i];
  rep(i, 1, N+1) sq[i] = (1 - pow(q, (double)i)) / (1 - q);

  rep(i, 0, N)rep(k, 0, i+1){
    // not take i-th contest
    chmax(dp[i+1][k], dp[i][k]);

    // take i-th contest
    chmax(dp[i+1][k+1], q * dp[i][k] + P[i]);
  }
  rep(k, 1, N+1) chmax(answer, dp[N][k]/sq[k] - 1200/sqrt(k));

  cout << fixed << setprecision(9) << answer << endl;
  return 0;
}