#include<iostream>
#include<string>
#include<deque>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int pfx[500010];

int main(){
  string X; cin >> X;
  rep(i, 0, X.size()) pfx[i + 1] = pfx[i] + (int)(X[i] - '0');

  int c = 0;
  deque<char> ans;
  rep(i, 0, X.size()){
    ans.push_front( (char)((pfx[X.size() - i] + c) % 10 + '0') );
    c = (pfx[X.size() - i] + c) / 10;
  }
  while(c){
    ans.push_front( (char)(c % 10 + '0') );
    c /= 10;
  }
  while(ans.front() == '0') ans.pop_front();

  while(!ans.empty()){
    cout << ans.front();
    ans.pop_front();
  }

  cout << endl;
  return 0;
}