#include<iostream>
#include<unordered_set>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

bool dp[100010];
int A[11];

int main(){
  int N; cin >> N;
  rep(i, 0, N) cin >> A[i];
  int M; cin >> M;
  unordered_set<int> B;
  rep(i, 0, M){
    int b; cin >> b;
    B.insert(b);
  }

  int X; cin >> X;

  dp[0] = true;
  rep(c, 0, X)if(dp[c]){
    rep(n, 0, N)if(c + A[n] <= X){
      if(B.count(c + A[n]) == 1) continue;
      if(c + A[n] < X) dp[c + A[n]] = true;
      if(c + A[n] == X){
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  
  cout << "No" << endl;
  return 0;
}