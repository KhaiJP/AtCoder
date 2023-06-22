#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int A[11], a[55], b[55], c[55], d[55], N, M, Q, answer, len;

void dfs(int pre){
  if(len == N){
    rep(i, 0, N) cout << A[i] << ' '; cout << '\n';
    int tmp = 0;
    rep(i, 0, Q)if(A[b[i]] - A[a[i]] == c[i]) tmp += d[i];
    answer = max(answer, tmp);
    return ;
  }

  A[len] = pre;
  rep(i, pre, M+1){
    ++len;
    dfs(i);
    --len;
  }
  A[len] = 0;
  return ;
}

int main(){
  cin >> N >> M >> Q;
  rep(i, 0, Q) cin >> a[i] >> b[i] >> c[i] >> d[i];
  rep(i, 1, M+1) dfs(i);

  cout << answer << endl;
  return 0;
}