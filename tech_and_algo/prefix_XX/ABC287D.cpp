#include<iostream>
#include<string>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

// f[n] : if first n chars of S matches first n chars of T, b for last.
bool f[300010], b[300010];

int main(){
  string S, T; cin >> S >> T;
  int s = S.size(), t = T.size();

  // 0 char choise is considered to always correspond
  f[0] = true, b[0] = true;

  rep(i, 1, t+1){
    // once f[i] = false, f[j] = false for j >= i. same for b
    f[i] = f[i-1] && ( S[i-1] == '?'  ||  T[i-1] == '?'  ||  S[i-1] == T[i-1] );
    b[i] = b[i-1] && ( S[s-i] == '?'  ||  T[t-i] == '?'  ||  S[s-i] == T[t-i] );
  }

  rep(i, 0, t+1) cout << (f[i] && b[t-i] ? "Yes" : "No") << '\n';
  return 0;
}