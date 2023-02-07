#include<iostream>
#include<queue>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  int N; cin >> N;
  priority_queue<int> cards;
  
  rep(i, 0, N){
    int a; cin >> a;
    cards.push(a);
  }
  bool alice_turn = true;
  int points[2] = {0, 0};
  while(!cards.empty()){
    points[alice_turn] += cards.top();
    cards.pop();
    alice_turn = !alice_turn;
  }

  cout << points[1] - points[0] << endl;
  return 0;
}