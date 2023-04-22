#include<iostream>
#include<set>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  int N; cin >> N;
  string S; cin >> S;

  set<char> s; for(char c : S) s.insert(c);
  if(s.size() == 1){
    cout << -1 << endl;
    return 0;
  }


  int level = 0;
  int answer = 0;
  S += '-';
  rep(r, 0, N){
    while(S[r] == 'o'){
      ++r;
      ++level;
    }

    answer = max(answer, level);
    level = 0;
  }

  cout << answer << endl;
  return 0;
}