#include<iostream>
#include<vector>
#include<set>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define fore(a, v) for(auto a : v)

set<int> S[11];

int main(){
  int N, M; cin >> N >> M;
  rep(i, 0, M){
    int C; cin >> C;
    rep(c, 0, C){
      int a; cin >> a;
      S[i].insert(a);
    }
  }


  // bit-brute-force
  int ans = 0;
  int mx = (1 << M);
  rep(i, 1, mx){
    vector<int> v;
    int j = i;
    int ord = 0;
    while (j > 0){
      if(j & 1) v.push_back(ord);
      ++ord;
      j >>= 1;
    }

    set<int> ref;
    fore(k, v)fore(a, S[k]) ref.insert(a);
    
    ans += ref.size() == N;
  }

  cout << ans << endl;

  return 0;
}