#include<iostream>
#include<set>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int A[1500010], count[1500010];

int main(){
  int N, M; cin >> N >> M;
  rep(i, 0, N) cin >> A[i];
  set<int> pool; rep(i, 0, N+1) pool.insert(i);

  rep(i, 0, M){
    ++count[A[i]];
    if(count[A[i]] == 1) pool.erase(A[i]);
  }

  
  int answer = min(N, *pool.begin());
  rep(i, M, N){
    ++count[A[i]], --count[A[i - M]];

    if(A[i] != A[i - M]){
      if(count[A[i]] == 1) pool.erase(A[i]);
      if(count[A[i - M]] == 0) pool.insert(A[i - M]);
    }

    answer = min(answer, *pool.begin());
  }

  cout << answer << endl;
  return 0;
}