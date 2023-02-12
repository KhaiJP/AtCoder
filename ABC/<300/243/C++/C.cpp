#include<iostream>
#include<unordered_map>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define fore(a, v) for(auto a : v)
#define yes "Yes"
#define noo "No"

int X[200010], Y[200010];
int MAX = 1000000001;

int main(){
  int N; cin >> N;
  rep(i, 0, N) cin >> X[i] >> Y[i];

  // y_move[y].first   : left-most point on y=y that goes right
  // y_move[y].second  : right-most point on y=y that goes left
  unordered_map< int, pair<int, int> > y_move;
  string S; cin >> S;
  rep(i, 0, N){
    char &c = S[i];   int  &x = X[i],   &y = Y[i]; 
    
    if(c == 'R'){
      if(y_move.count(y) == 1) y_move[y].first = min(y_move[y].first, x);
      else y_move[y] = {x, -1}; 
    }

    if(c == 'L'){
      if(y_move.count(y) == 1) y_move[y].second = max(y_move[y].second, x);
      else y_move[y] = {MAX, x};
    }
  }

  fore(pr, y_move){
    pair<int, int> &lr_mosts = pr.second;
    // if "the left-most that goes right" < "the right-most that goes left" then a collision occurs
    if(lr_mosts.first < lr_mosts.second) { cout << yes << endl; return 0;}
  }

  cout << noo << endl;
  return 0;
}