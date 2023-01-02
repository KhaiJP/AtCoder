#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
#define rep(i,s,t) for(int i=(s); i<(t); ++i)
using namespace std;

int main(){
  int H, W, rs, cs; cin >> H >> W >> rs >> cs;
  int N; cin >> N;
  unordered_map<int, vector<int>> R, C;
  rep(i,0,N){
    int r, c; cin >> r >> c;
    R[r].push_back(c), C[c].push_back(r);
  }
  for(auto &p : R) sort(p.second.begin(), p.second.end());
  for(auto &p : C) sort(p.second.begin(), p.second.end());

  int Q; cin >> Q;
  char d; int l;
  rep(q, 0, Q){
    cin >> d >> l;
    if(d == 'L'){
      int block = 0;
      if(R.count(rs)==1){
        auto itr = lower_bound(R[rs].begin(), R[rs].end(), cs);
        if(itr != R[rs].begin()) itr--, block = *itr;
      }
      cs = max(cs-l, block+1);
    }
    if(d == 'R'){
      int block = W+1;
      if(R.count(rs)==1){
        auto itr = upper_bound(R[rs].begin(), R[rs].end(), cs);
        if(itr != R[rs].end()) block = *itr;
      }
      cs = min(cs+l, block-1);
    }
    if(d == 'U'){
      int block = 0;
      if(C.count(cs)==1){
        auto itr = lower_bound(C[cs].begin(), C[cs].end(), rs);
        if(itr != C[cs].begin()) itr--, block = *itr;
      }
      rs = max(rs-l, block+1);
    }
    if(d == 'D'){
      int block = H+1;
      if(C.count(cs)==1){
        auto itr = upper_bound(C[cs].begin(), C[cs].end(), rs);
        if(itr != C[cs].end()) block = *itr;
      }
      rs = min(rs+l, block-1);
    }
    cout << rs << ' ' << cs << '\n';
  }
  return 0;
}