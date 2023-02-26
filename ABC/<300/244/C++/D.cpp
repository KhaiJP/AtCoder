#include<iostream>
#include<set>
#include<utility>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define yes "Yes"
#define noo "No"

int main(){
  string S = "", T = "";
  rep(i,0,3){char c; cin >> c; S += c;}
  rep(i,0,3){char c; cin >> c; T += c;}
  set<string> ref;
  ref.insert(S);
  swap(S[0], S[1]);
  swap(S[0], S[2]);
  ref.insert(S);
  swap(S[0], S[1]);
  swap(S[0], S[2]);
  ref.insert(S);

  cout << ( ref.count(T) == 1 ? yes : noo ) << endl;
  return 0;
}