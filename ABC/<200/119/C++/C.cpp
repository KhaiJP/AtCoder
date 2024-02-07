#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int N, ABC[3], l[10], L[5], cnt[5], answer = 1e9;

void dfs(int n){
  if(n == N){
    if(L[0] == 0 || L[1] == 0 || L[2] == 0){
      return ;
    }
    int tmp = 0;
    rep(i, 0, 3) tmp += 10 * (cnt[i] - 1);
    rep(i, 0, 3) tmp += abs(L[i] - ABC[i]);
    answer = min(answer, tmp);
    return ;
  }

  rep(i, 0, 4){
    ++cnt[i];
    L[i] += l[n];
    dfs(n+1);
    L[i] -= l[n];
    --cnt[i];
  }
  return ;
}



int main(){
  cin >> N;
  rep(i, 0, 3) cin >> ABC[i];
  rep(i, 0, N) cin >> l[i];
  dfs(0);
  cout << answer << endl;
  return 0;
}