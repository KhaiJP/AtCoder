#include<iostream>
#include<set>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define yes "Yes"
#define noo "No"


int main(){
  int N; cin >> N;
  set<pair<int, int>> history;
  int x = 0, y = 0;
  history.insert({x, y});

  rep(i,0,N){
    char d; cin >> d;
    if(d == 'R') x++;
    if(d == 'L') x--;
    if(d == 'U') y++;
    if(d == 'D') y--;
    if(histroy.count({x, y}) == 1){
      cout << yes << endl;
      return 0;
    }
    history.insert({x, y});
  }
  cout << noo << endl;

  return 0;
}