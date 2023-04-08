#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

pair<int, int> ranges[10010], S_T[110];
int current_place[110], answer[110];

// JUST DO IT!!
int main(){
  int N, D, K; cin >> N >> D >> K;
  rep(d, 0, D){
    int L, R; cin >> L >> R;
    ranges[d] = {L, R};
  }
  rep(k, 0, K){
    int S, T; cin >> S >> T;
    S_T[k] = {S, T};
    current_place[k] = S;
  }

  rep(d, 0, D){
    int &L = ranges[d].first,  &R = ranges[d].second;
    // cout << "====================================" << '\n';
    // cout << "day" << d+1 << ": L = " << L << ", R = " << R << '\n';
    rep(k, 0, K){
      int &cp = current_place[k], &T = S_T[k].second;
      if(answer[k] > 0 || cp < L || R < cp) continue;
      // cout << "- - - - - - - - - - - - - - - -" << '\n';
      // cout << "city  " << k+1 << ": cp = " << cp << ", T = " << T << '\n';
      if(cp < T && cp <= R) cp = min(R, T);
      if(cp > T && cp >= L) cp = max(L, T);
      if(cp == T) answer[k] = d + 1;
    }
  }

  rep(k, 0, K) cout << answer[k] << endl;
  return 0;
}