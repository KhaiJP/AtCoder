#include<iostream>
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
    int j = i, ord = 0;
    set<int> ref;

    while (j > 0){
      if(j & 1)fore(a, S[ord]) ref.insert(a);
      ++ord;
      j >>= 1;
    }
    
    ans += ref.size() == N;
  }

  cout << ans << endl;
  return 0;
}