#include<iostream>
#define rep(i,s,t) for(int i=(s); i<(t); ++i)
using namespace std;

int main(){
  int N; cin >> N;
  int prev_t = 0, prev_x = 0, prev_y = 0;
  bool flag = true;

  rep(i,0,N){
    int t, x, y; cin >> t >> x >> y;
    // define deltas
    int delta_t = t-prev_t, delta_x = x-prev_x, delta_y = y-prev_y;
    // update postition
    prev_t = t, prev_x = x, prev_y = y;
    // close enough? && valid parity?
    if(abs(delta_x)+abs(delta_y)<=delta_t && (delta_x+delta_y+delta_t)%2==0) continue;
    // else
    flag = false;
    break;
  }
  cout << (flag ? "Yes" : "No") << endl;
  return 0;
}