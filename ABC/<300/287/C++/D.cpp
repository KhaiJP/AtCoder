#include<iostream>
#include<vector>
#include<string>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define yes "Yes"
#define noo "No"

int main(){
  string S, T; cin >> S >> T;
  int s = S.size();
  int t = T.size();

  // f[i]: if first i chars of S match the first i chars of T
  // b[i]: if last i chars of S match the last i chars of T 
  vector<bool> f(t+1 , false), b(t+1 , false);
  // We recognize 0 char choise is always true 
  f[0] = true;
  b[0] = true;

  rep(i,1,t+1){
    // once f[i] = false, f[j] = false for j >= i. same for b
    f[i] = f[i-1] && (S[i-1] == '?' || T[i-1] == '?' || S[i-1] == T[i-1]);
    b[i] = b[i-1] && (S[s-i] == '?' || T[t-i] == '?' || S[s-i] == T[t-i]);
  }

  rep(i,0,t+1) cout << (f[i] && b[t-i] ? yes : noo) << '\n';
  return 0;
}