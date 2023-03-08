#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define yes "Yes"
#define noo "No"

bool dp[110][10010];
int  a[110], b[110];

int main(){
  int N, X; cin >> N >> X;
  rep(i, 0, N) cin >> a[i] >> b[i];
  dp[0][0] = true;

  rep(n, 0, N)rep(i, 0, X){
    if(!dp[n][i]) continue;
    if(i + a[n] <= X) dp[n+1][i+a[n]] = true;
    if(i + b[n] <= X) dp[n+1][i+b[n]] = true;
  }

  cout << (dp[N][X] ? yes : noo) << endl;
  return 0;
}