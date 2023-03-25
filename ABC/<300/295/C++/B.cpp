#include<iostream>
#include<iomanip>
#include<map>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define fore(a, v)   for(auto a : v)

char Field[22][22];
int main(){
  map<pair<int, int>, int> m;

  int R, C; cin >> R >> C;
  rep(r, 0, R)rep(c, 0, C){
    char B; cin >> B;
    if(B == '.' || B == '#') Field[r][c] = B;
    else m[{r,c}] = (char)(B - '0');
  }

  fore(p, m){
    rep(r, 0, R)rep(c, 0, C){
      if(abs(r-p.first.first) + abs(c-p.first.second) <= p.second) Field[r][c] = '.';
    }
  }
  rep(r, 0, R){
    rep(c, 0, C) cout << Field[r][c]; cout << '\n';
  }
  return 0;
}