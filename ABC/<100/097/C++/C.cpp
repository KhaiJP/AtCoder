#include<iostream>
#include<string>
#include<set>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)


int main(){
  string s; cin >> s;
  set<string> S;
  rep(i, 0, s.size())rep(j, 1, 6) S.insert(s.substr(i, j));
  
  int K; cin >> K;
  auto itr = S.begin(); rep(i, 1, K) ++itr;
  cout << *itr << endl;
  return 0;
}