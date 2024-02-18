#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int H, W, N, answer;
bool F[550][550];
string T;

bool check(int row, int col){
  for(char c : T){
    if(c == 'L') col -= 1;
    if(c == 'R') col += 1;
    if(c == 'U') row -= 1;
    if(c == 'D') row += 1;
    if(!F[row][col]) return false;
  }
  return true;
}

int main(){
  cin >> H >> W >> N >> T;
  rep(i, 1, H+1)rep(j, 1, W+1){
    char c; cin >> c;
    F[i][j] = c == '.';
  }

  rep(i, 1, H+1)rep(j, 1, W+1) answer += F[i][j] && check(i, j);
  cout << answer << endl;
  return 0;
}