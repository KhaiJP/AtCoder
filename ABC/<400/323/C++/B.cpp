#include<iostream>
#include<set>
using namespace std;
using P = pair<int, int>;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

set<P> s;

int main(){
  int N; cin >> N;
  rep(i, 0, N){
    int cnt = 0;
    rep(j, 0, N){
      char c; cin >> c;
      cnt += c == 'o';
    }
    s.insert({-cnt, i+1});
  }

  for(auto p : s) cout << p.second << ' ';
  cout << endl;
  return 0;
}