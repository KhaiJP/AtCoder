#include<iostream>
#include<vector>
#include<map>
#include<vector>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  int N, M; cin >> N >> M;
  vector<string> S(N);
  rep(n,0,N){
    string s; cin >> s;
    S[n] = s.substr(3,3); 
  }

  map<string, bool> isHappened;
  rep(i,0,M){
    string t; cin >> t;
    isHappened[t] = true;
  }
  
  int answer = 0;
  rep(i,0,N){
    answer += (isHappened[S[i]] ? 1 : 0);
  }
  cout << answer << endl;
  return 0;
}