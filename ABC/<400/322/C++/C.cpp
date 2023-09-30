#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int N, M, A[200010];

int main(){
  cin >> N >> M;
  rep(i, 0, M) cin >> A[i];
  rep(i, 1, N+1){
    int d = A[lower_bound(A, A+M, i) - A];
    cout << d - i << endl;
  }
  return 0;
}