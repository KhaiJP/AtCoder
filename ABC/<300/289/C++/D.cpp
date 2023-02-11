#include<iostream>
#include<unordered_set>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define yes "Yes"
#define noo "No"

int A[12];
bool dp[100010];
unordered_set<int> B;

int main(){
  int N; cin >> N;
  rep(i, 0, N) cin >> A[i];
  
  int M; cin >> M;
  rep(i, 0, M){
    int b; cin >> b;
    B.insert(b);
  }

  int X; cin >> X;
  dp[0] = true;

  rep(i, 0, X){
    if(!dp[i]) continue;
    rep(n, 0, N)if(B.count(i + A[n]) != 1 && i+A[n] <= X) dp[i+A[n]] = true;
  }

  cout << (dp[X] ? yes : noo) << endl;
  return 0;
}