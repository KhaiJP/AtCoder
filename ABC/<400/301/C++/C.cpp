#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define repc(c) for(char c = 'a'; c != 'z'+1; ++c)

int main(){
  map<char, int> cntS, cntT;
  string S, T; cin >> S >> T;

  string atr = "atcoder";

  for(auto c : S) ++cntS[c];
  for(auto c : T) ++cntT[c];
  
  int shortage_S = 0, shortage_T = 0;
  repc(c){
    if(cntS[c] == cntT[c]) continue;
    else if(count(atr.begin(), atr.end(), c) > 0){
      if(cntS[c] > cntT[c]) shortage_T += cntS[c] - cntT[c];
      else shortage_S += cntT[c] - cntS[c];
    }
    else{
      cout << "No" << endl;
      return 0;
    }
  }
  
  if(shortage_S <= cntS['@'] && shortage_T <= cntT['@']) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}