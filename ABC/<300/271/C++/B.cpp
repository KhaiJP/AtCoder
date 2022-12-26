#include<iostream>
#include<vector>
#define rep(i,s,t) for(int i=(s); i<(t); ++i)
using namespace std;

int main(){
  int N, Q; cin >> N >> Q;
  vector<vector<int>> M;
  rep(i, 0, N){
    int L; cin >> L;
    vector<int> v_tmp(L);
    rep(j,0,L) cin >> v_tmp[j];
    M.push_back(v_tmp);
  }
  rep(i, 0, Q){
    int s, t; cin >> s >> t;
    cout << M[s-1][t-1] << '\n';
  }
  return 0;
}