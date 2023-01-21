#include<iostream>
#include<vector>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  int N, P, Q, R, S; cin >> N >> P >> Q >> R >> S;
  vector<int> A(N+1, 0); rep(i,1,N+1) cin >> A[i];
  rep(i,1,P)     cout << A[i] << ' ';
  rep(i,0,Q-P+1) cout << A[R+i] << ' ';
  rep(i,Q+1,R)   cout << A[i] << ' ';
  rep(i,0,S-R+1) cout << A[P+i] << ' ';
  rep(i,S+1,N+1) cout << A[i] << ' ';
  cout << endl;
  return 0;
}