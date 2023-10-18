#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define SHEEP 1
#define WOLF 0

int N, sheep_or_wolf[100010];
string s;

int main(){
  cin >> N >> s;
  s += s[0];
  rep(i, 0, 4){
    sheep_or_wolf[0] = i&1, sheep_or_wolf[1] = (i&2) >> 1;
    rep(j, 1, N+1){
      if(sheep_or_wolf[j] == SHEEP && s[j] == 'o'){
        sheep_or_wolf[j+1] = sheep_or_wolf[j-1];
      }
      if(sheep_or_wolf[j] == SHEEP && s[j] == 'x'){
        sheep_or_wolf[j+1] = 1 - sheep_or_wolf[j-1];
      }
      if(sheep_or_wolf[j] == WOLF && s[j] == 'o'){
        sheep_or_wolf[j+1] = 1 - sheep_or_wolf[j-1];
      }
      if(sheep_or_wolf[j] == WOLF && s[j] == 'x'){
        sheep_or_wolf[j+1] = sheep_or_wolf[j-1];
      }
    }
    if(sheep_or_wolf[0] == sheep_or_wolf[N] &&
       sheep_or_wolf[1] == sheep_or_wolf[N+1] ){
      rep(j, 0, N) cout << (sheep_or_wolf[j] == SHEEP ? 'S' : 'W');
      cout << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}