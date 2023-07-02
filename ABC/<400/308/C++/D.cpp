#include<iostream>
#include<string>
#include<deque>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int DR[] = {-1,  0,  1,  0, -1,  1,  1, -1};
int DC[] = { 0,  1,  0, -1,  1,  1, -1, -1};

char F[510][510];
bool reached[510][510];
string snuke = "snuke";

int main(){
  int H, W; cin >> H >> W;
  rep(i, 0, H){
    string S; cin >> S;
    rep(j, 0, W) F[i+1][j+1] = S[j];
  }

  if(F[1][1] != 's'){
    cout << "No" << endl;
    return 0;
  }

  deque<pair<pair<int, int>, int>> q;
  q.push_back({{1, 1}, 0});
  reached[1][1] = true;

  while(!q.empty()){
    int i = q.front().first.first, j = q.front().first.second;
    int c = q.front().second;
    q.pop_front();

    rep(k, 0, 4){
      int ni = i + DR[k], nj = j + DC[k];
      int nc = (c+1) % 5;
      if(F[ni][nj] == snuke[nc] && !reached[ni][nj]){
        reached[ni][nj] = true;
        q.push_back( { {ni, nj}, nc } );
      }
    }
  }

  cout << (reached[H][W] ? "Yes" : "No") << endl;
  return 0;
}