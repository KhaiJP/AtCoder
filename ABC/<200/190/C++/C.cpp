#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int N, M, K, answer;
int A[110], B[110], CD[2][20];
bool ball_put[110];

void dfs(int k = 0){
  if(k == K){
    int tmp = 0;
    rep(i, 0, M) tmp += ball_put[A[i]] && ball_put[B[i]];
    answer = max(answer, tmp);
    return ;
  }

  rep(j, 0, 2){
    bool buff = ball_put[CD[j][k]];
    ball_put[CD[j][k]] = true;
    dfs(k+1);
    ball_put[CD[j][k]] = buff;
  }
}


int main(){
  cin >> N >> M;
  rep(i, 0, M){
    cin >> A[i] >> B[i];
    --A[i], --B[i];
  }

  cin >> K;
  rep(i, 0, K){
    cin >> CD[0][i] >> CD[1][i];
    --CD[0][i], --CD[1][i];
  }

  dfs();
  cout << answer << endl;
  return 0;
}