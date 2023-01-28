#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define fore(a, v) for(auto a : v)

int main(){
  int N; cin >> N;
  vector<vector<int>> S(N+1);
  rep(i,1,N+1){
    int A; cin >> A;
    S[A].push_back(i);
  }

  int Q; cin >> Q;
  rep(q,0,Q){
    int L, R, X; cin >> L >> R >> X;
    auto dR = lower_bound(S[X].begin(), S[X].end(), R+1);
    auto dL = lower_bound(S[X].begin(), S[X].end(), L);
    int  d  = distance(dL, dR);
    cout << d << '\n';
  }
  return 0;
}