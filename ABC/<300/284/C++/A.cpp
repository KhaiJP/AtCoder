#include<iostream>
#include<vector>
#include<string>
using namespace std;
#define rep(i, s, t) for (int i = (s); i < (t); ++i)

int main(){
  int n; cin >> n;
  vector<string> s(n); rep(i,0,n) cin >> s[i];
  rep(i,0,n) cout <<s[n-1-i] << '\n';
  return 0;
}