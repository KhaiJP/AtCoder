#include<iostream>
#include<string>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define rrep(i, s, t) for(int i = (s); i >= (t); --i)
#define fore(a, v) for(auto a : v)

int main(){
  // S is S' in this code
  string S, T; cin >> S >> T;
  int s = S.size(), t = T.size();

  // to find the lexicographically smallest, T-search must be begun fron the tail of S'
  rrep(i, s-1, t-1){
    if(S[i] == '?' || S[i] == T[t-1]){

      // check if all chars in T match S[i - (t-1)]:S[i - (0)]
      bool T_contained = true;
      rep(j, 1, t)if(S[i-j] != '?' && S[i-j] != T[t-1-j]) T_contained = false;

      if(T_contained){
        // make S[i - (t-1)]:S[i - (0)] be T
        rep(j, 0, t) S[i-j] = T[t-1-j];
        // to make S be lexicographically smallest, all '?'s must be 'a' and this is enough
        fore(c, S) cout << (c == '?' ? 'a' : c);
        cout << endl;
        return 0;
      }

    }

  }

  cout << "UNRESTORABLE" << endl;
  return 0;
}