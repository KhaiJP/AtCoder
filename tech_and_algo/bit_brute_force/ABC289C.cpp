#include<iostream>
#include<set>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

set<int> S[11];

int main(){
  int N, M; cin >> N >> M;
  rep(i, 0, M){
    int C; cin >> C;
    rep(j, 0, C){
      int a; cin >> a;
      S[i].insert(a);
    }
  }

  int answer = 0;

  rep(chosen_sets, 0, 1<<M){
    bool contained_all = true;

    rep(x, 1, N+1){
      bool contained_one_of_them = false;
      rep(j, 0, M)if( chosen_sets & (1<<j) ){
        contained_one_of_them = contained_one_of_them || S[j].count(x) == 1;
      }
      
      contained_all = contained_all && contained_one_of_them;
    }

    answer += contained_all;
  }

  cout << answer << endl;
  return 0;
}