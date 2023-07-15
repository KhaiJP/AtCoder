#include<iostream>
#include<string>
#include<algorithm>
#include<set>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  set<string> s;
  int N; cin >> N;
  rep(i, 0, N){
    string S; cin >> S;
    string T = S;
    reverse(S.begin(), S.end());
    S = min(S, T);
    s.insert(S);
  }
  
  cout << s.size() << endl;
  return 0;
}