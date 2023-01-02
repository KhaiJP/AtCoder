#include<iostream>
#include<vector>
#define rep(i,s,t) for(int i=(s); i<(t); ++i)
using namespace std;

int main(){
  int N; cin >> N;
  vector<int> P(N); rep(i,0,N) cin >> P[i];
  vector<int> lg(N,0); // lg[# of turns] = # of happy people
  rep(person,0,N){
    int& happy_man = P[person];
    // P[person], P[person]+1, P[person]-1 would be happy if P[person] is in front of him/her
    // (P[person]-person +N)mod N times rotations are required for the first one.
    rep(delta, -1, 2) lg[(happy_man+delta - person + N)%N] += 1;
  }
  int answer = 0;
  rep(i,0,N) answer = max(answer, lg[i]);
  cout << answer << endl;
  return 0;
}