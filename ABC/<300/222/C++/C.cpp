#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

// wins_id[i] : first -> number of wins, second -> id, whose rank is i;
pair<int, int> wins_id[60];
char hand[110][110];

bool formerWins(int p1, int p2, int match){
  if( hand[p1][match] == 'G' && hand[p2][match] == 'C' ) return true;
  if( hand[p1][match] == 'C' && hand[p2][match] == 'P' ) return true;
  if( hand[p1][match] == 'P' && hand[p2][match] == 'G' ) return true;
  return false;
}

int main(){
  int N, M; cin >> N >> M;
  rep(i, 1, 2*N+1)rep(j, 0, M) cin >> hand[i][j];

  rep(i, 1, 2*N+1) wins_id[i] = {0, i};
  rep(match, 0, M){
    rep(i, 1, N+1){
      pair<int, int> &p1 = wins_id[2*i-1], &p2 = wins_id[2*i];
      if(formerWins(p1.second, p2.second, match)) --p1.first;
      if(formerWins(p2.second, p1.second, match)) --p2.first;
    }
    sort(wins_id+1, wins_id+2*N+1);
  }
  
  rep(i, 1, 2*N+1) cout << wins_id[i].second << ' ';
  cout << endl;
  return 0;
}