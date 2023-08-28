#include<iostream>
#include<vector>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int N, A[220], s;
vector<vector<int>> R[200];

int main(){
  cin >> N;
  rep(i, 0, N) cin >> A[i+1];
  // solve according to pigeonhole principle
  rep(i, 1, 1 << min(N, 8)){
    int t = 0, j = i;
    vector<int> v;
    while(j){
      int k = j&1;
      v.push_back(k);
      t = (t + v.back() * A[v.size()]) % 200;
      j >>= 1;
    }
    R[t].push_back(v);
  }

  rep(r, 0, 200)if(R[r].size() > 1){
    cout << "Yes" << endl;
    auto &v1 = R[r][0];
    rep(i, 0, v1.size()) s += v1[i];
    cout << s << ' ';
    rep(i, 0, v1.size())if(v1[i]) cout << i+1 << ' ';
    cout << endl;

    s = 0;

    auto &v2 = R[r][1];
    rep(i, 0, v2.size()) s += v2[i];
    cout << s << ' ';
    rep(i, 0, v2.size())if(v2[i]) cout << i+1 << ' ';
    cout << endl;
    return 0;
  }

  cout << "No" << endl;
  return 0;
}