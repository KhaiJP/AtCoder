#include<iostream>
#include<vector>
#include<map>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define yes "Yes"
#define noo "No"

int main(){
  int N, X; cin >> N >> X;
  map<int, int> m;
  rep(i,0,N){
    int A, B; cin >> A >> B;
    m[A] = B;
  }
  vector dp(N+1, vector<int>(X+1, -1));
  dp[0][0] = 0;
  
  auto itr = m.begin();
  rep(n,0,N){
    const int &A = (*itr).first;
    rep(x, 0, X+1){
      if(dp[n][x] == -1) continue;
      // use b coins
      rep(b, 0, m[A]+1)if(x+b*A <= X) dp[n+1][x+b*A] = 1;
    }
    ++itr;
  }
  cout << (dp[N][X] == 1 ? yes : noo) << endl; 
  return 0;
}