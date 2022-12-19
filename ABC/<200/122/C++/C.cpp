#include<iostream>
#include<vector>
#include<string>
#define rep(i,s,t) for(int i=(s); i<(t); ++i)
using namespace std;

int main(){
  int N, Q; cin >> N >> Q;
  string S; cin >> S;
  vector<int> hasAC(N, 0);
  rep(i,0,N-1){
    hasAC[i] = (S[i]=='A' && S[i+1]=='C') ? 1 : 0;
  }
  vector<int> pfx(N+1, 0);
  rep(i,1,N){
    pfx[i] = pfx[i-1] + hasAC[i-1];
  }
  rep(i,0,Q){
    int l, r; cin >> l >> r;
    cout << pfx[r-1]-pfx[l-1] << '\n';
  }
  cout << endl;
  return 0;
}
