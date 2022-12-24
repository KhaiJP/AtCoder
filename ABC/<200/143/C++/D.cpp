#include<iostream>
#include<vector>
#include<algorithm>
#define rep(i,s,t) for(int i=(s); i<(t); ++i)
using namespace std;

int main(){
  int32_t N; cin >> N;
  vector<int32_t> L(N); rep(i,0,N) cin >> L[i];
  sort(L.begin(), L.end());
  int64_t answer = 0;
  rep(arg_b,0,N) rep(arg_a, 0, arg_b){
    int argmax = lower_bound(L.begin(), L.end(), L[arg_a]+L[arg_b]) - L.begin();
    int argmin = arg_b+1;
    answer += max(0, argmax-argmin);
  }
  cout << answer << endl;
  return 0;
}