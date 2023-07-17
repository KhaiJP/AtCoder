#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int bought[15], N, M, X, A[15][15], C[15], answer;

void dfs(int pre = 0){
  if(pre == N){
    // check if all the algos are acquired
    rep(j, 0, M){
      int score = 0;
      rep(i, 0, N) score += bought[i] * A[i][j];
      if(score < X) return ;
    }

    // check if total cost updates the minimum
    int tmp = 0;
    rep(i, 0, N) tmp += bought[i] * C[i];
    answer = min(answer, tmp);
    return ;
  }
  
  rep(i, 0, 2){
    bought[pre] = i;
    dfs(pre+1);
  }

  return ;
}

int main(){
  cin >> N >> M >> X;
  rep(i, 0, N){
    cin >> C[i];
    rep(j, 0, M) cin >> A[i][j];
  }

  answer = 1e9;
  dfs();
  cout << ( answer == 1e9 ? -1 : answer ) << endl;
  return 0;
}