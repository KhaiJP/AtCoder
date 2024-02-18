#include<iostream>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

ll N, A[200010];

int main(){
  cin >> N;
  rep(i, 1, N+1) cin >> A[i];
  rep(i, 1, N){
    ll S, T; cin >> S >> T;
    A[i+1] += T * (A[i]/S);
  }
  cout << A[N] << endl;
  return 0;
}