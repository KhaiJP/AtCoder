#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

void coordinate_compression(const vector<int> &vec, vector<int> &container){
  vector<int> tmp(vec.size());
  for (int i = 0; i < vec.size(); ++i) tmp[i] = vec[i];
  sort(tmp.begin(), tmp.end());

  tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
  for (int i = 0; i < vec.size(); ++i){
    container[i] = lower_bound(tmp.begin(), tmp.end(), vec[i]) - tmp.begin();
    container[i] += 1;
  }
}

int main(){
  int H, W, N; cin >> H >> W >> N;
  vector<int> A(N), B(N);
  rep(i, 0, N) cin >> A[i] >> B[i];

  vector<int> comA(N), comB(N);
  coordinate_compression(A, comA);
  coordinate_compression(B, comB);
  
  rep(i, 0, N) cout << comA[i] << ' ' << comB[i] << '\n';
  cout << endl;
  return 0;
}