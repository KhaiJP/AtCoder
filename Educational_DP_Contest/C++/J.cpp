#include<iostream>
#include<iomanip>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

double dp[330][330][330], p = 1;
int N, cnt[5];
bool F[330][330][330];

double dfs(int i, int j, int k){
  if(F[i][j][k]) return dp[i][j][k];
  if(i==0 && j==0 && k==0) return 0.0;

  if(i > 0) dp[i][j][k] += dfs(i-1, j, k)   * i;
  if(j > 0) dp[i][j][k] += dfs(i+1, j-1, k) * j;
  if(k > 0) dp[i][j][k] += dfs(i, j+1, k-1) * k;

  dp[i][j][k] += N;
  dp[i][j][k] /= i + j + k;
  F[i][j][k] = true;
  return dp[i][j][k];
}

int main(){
  cin >> N;
  rep(i, 0, N){
    int a; cin >> a;
    ++cnt[a];
  }
  cout << fixed << setprecision(10) << dfs(cnt[1], cnt[2], cnt[3]) << endl;
  return 0;
}