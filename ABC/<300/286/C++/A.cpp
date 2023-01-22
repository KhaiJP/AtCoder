#include<iostream>
#include<vector>
#include<utility>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  int N, P, Q, R, S; cin >> N >> P >> Q >> R >> S;
  vector<int> A(N+1, 0); rep(i,1,N+1) cin >> A[i];

  rep(i,0,Q-P+1) swap(A[P+i], A[R+i]);
  
  rep(i,1,N+1) cout << A[i] << ' ';
  cout << endl;
  return 0;
}