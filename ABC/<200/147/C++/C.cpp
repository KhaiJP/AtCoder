#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int F[20][20], r[20], answer, N;

void dfs(int n = 0, int k = 0){
  if(n == N){
    bool flag = true;
    rep(def, 1, n+1)rep(wit, 1, N+1)if(r[wit] == 1 && F[wit][def] != -1){
      flag = flag && r[def] == F[wit][def];
      if(!flag) return;
    }
    answer = max(answer, k);
    return ;
  }
  rep(i, 0, 2){
    r[n+1] = i;
    dfs(n+1, k+i);
    r[n+1] = 0;
  }
  return ;
}

int main(){
  cin >> N;
  rep(i, 0, 20)rep(j, 0, 20) F[i][j] = -1;

  rep(witness, 1, N+1){
    int A; cin >> A;
    rep(i, 0, A){
      int x, y; cin >> x >> y;
      F[witness][x] = y;
    }
  }

  dfs();
  cout << answer << endl;
  return 0;
}
