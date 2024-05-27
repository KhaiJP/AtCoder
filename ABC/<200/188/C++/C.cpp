#include<iostream>
#include<queue>
using namespace std;
using Player = pair<int, int>;
using Game  = pair<Player, Player>;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)


int main(){
  int N; cin >> N;
  
  queue<Game> q;
  for(int i = 0; i < (1<<(N-1)); ++i){
    int A, B; cin >> A >> B;
    if(A < B) q.push({{A, 2*i+1}, {B, 2*i+2}});
    else      q.push({{B, 2*i+2}, {A, 2*i+1}});
  }

  while((int)q.size() > 1){
    queue<Game> tmp;

    while(q.size()){
      Game game1 = q.front(); q.pop();
      Game game2 = q.front(); q.pop();
      Player winner1 = game1.second;
      Player winner2 = game2.second;
      if(winner1.first < winner2.first) tmp.push({winner1,winner2});
      else tmp.push({winner2, winner1});
    }
    q = tmp;
  }
  
  Game final_game = q.front();
  Player loser = final_game.first;
  int loser_id = loser.second;
  cout << loser_id << endl;
  return 0;
}
