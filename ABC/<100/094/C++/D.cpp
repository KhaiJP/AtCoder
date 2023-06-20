#include<iostream>
#include<algorithm>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int A[100010];

int main(){
  int n; cin >> n;
  rep(i, 0, n) cin >> A[i];
  sort(A, A+n);

  int max_A = A[n-1];
  int half_A = max_A / 2;

  int pair_A = A[0];
  rep(i, 0, n-1)if(abs(A[i] - half_A) <= abs(pair_A - half_A)) pair_A = A[i];

  cout << max_A << ' ' << pair_A << endl;
  return 0; 
}