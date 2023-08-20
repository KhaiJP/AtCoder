#include<iostream>
#include<algorithm>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int N, M, answer, X[100010], delta[100010];

int main(){
  cin >> N >> M;
  rep(i, 0, M) cin >> X[i];
  sort(X, X+M);
  rep(i, 1, M) delta[i-1] = X[i] - X[i-1];
  sort(delta, delta+M-1);
  
  rep(i, 0, max(M-N, 0)) answer += delta[i];
  cout << answer << endl;
  return 0;
}