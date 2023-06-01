#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int LIS(const vector<int> &v){
  vector<int> dp;
  for(const auto &a : v){
    auto itr = lower_bound(dp.begin(), dp.end(), a);
    if(itr == dp.end()) dp.push_back(a);
    else *itr = a;
  }

  return dp.size();
}

int main(){
  int N; cin >> N;
  vector<int> c(N); rep(i, 0, N) cin >> c[i];

  cout << N - LIS(c) << endl;
  return 0;
}