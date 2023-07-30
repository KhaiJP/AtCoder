#include<iostream>
#include<algorithm>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int A[200010], B[200010], N, M;

int main(){
  cin >> N >> M;
  rep(i, 0, N) cin >> A[i]; sort(A, A+N);
  rep(i, 0, M) cin >> B[i]; sort(B, B+M);

  int l = 0, r = 1e9+1;
  while (l+1 < r){
    int m = (l + r) / 2;
    int nA = upper_bound(A, A+N, m) - A;
    int nB = B+M - lower_bound(B, B+M, m);

    if(nA >= nB) r = m;
    else        l = m;
  }

  cout << r << endl;
  return 0;
}
