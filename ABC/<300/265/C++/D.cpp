#include<iostream>
#include<set>
#define rep(i,s,t) for(int i=(s); i<(t); ++i)
using namespace std;

int main(){
  int N; cin >> N;
  int64_t P, Q, R; cin >> P >> Q >> R;
  set<int64_t> pfx_set({0});
  int64_t prev = 0;
  rep(i,0,N){
    int A; cin >> A;
    prev += A;
    pfx_set.insert(prev);
  }
  // let prefix sum be pfx, then P, Q and R can be written P = Sy - Sx, Q = Sz-Sy, R = Sw-Sz, respectively.
  // if we have found such Sx, then Sy, Sz and Sw are determined to be P+Sx, Q+P+Sx and R+Q+P+Sx, respectively.
  // Hence for given Sx, if all the P+Sx, Q+P+Sx and R+Q+P+Sx exist in pfx,
  // all the P, Q and R can be generated as the way shown in the problem 
  for(auto Sx : pfx_set){
    if(pfx_set.find(P+Sx)!=pfx_set.end() && pfx_set.find(Q+P+Sx)!=pfx_set.end() && pfx_set.find(R+Q+P+Sx)!=pfx_set.end()){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}