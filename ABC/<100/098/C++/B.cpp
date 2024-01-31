#include<iostream>
#include<set>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int N, answer;
set<int> S[30];

int main(){
  cin >> N;
  rep(i, 0, N){
    char c; cin >> c;
    int d = c - 'a';
    S[d].insert(i);
  }
  rep(i, 0, N){
    int cnt = 0;
    rep(c, 0, 26)if(S[c].size()){
      auto itr = S[c].lower_bound(i);
      cnt += ( itr != S[c].end() && itr != S[c].begin() ) ;
    }

    answer = max(answer, cnt);
  }

  cout << answer << endl;
  return 0;
}