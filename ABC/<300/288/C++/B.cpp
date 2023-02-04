#include<iostream>
#include<set>
#include<string>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define fore(a, v) for(auto a : v)

int main(){
  int N, K; cin >> N >> K;

  // set container is sorted
  set<string> S;
  rep(i,0,K){
    string s; cin >> s;
    S.insert(s);
  }

  fore(s, S) cout << s << '\n';
  cout << endl;
  return 0;
}