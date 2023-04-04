#include<iostream>
#include<string>
#include<set>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

set<string> usernames;

int main(){
  int N; cin >> N;
  rep(i, 1, N+1){
    string S; cin >> S;
    bool inserted = usernames.insert(S).second;
    if(inserted) cout << i << '\n';
  }
  cout << endl;
  return 0;
}