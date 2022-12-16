#include<iostream>
using namespace std;

int main(){
  int64_t W, H, x, y; cin >> W >> H >> x >> y;
  double answer = (double)W*(double)H/2.0; 
  cout << answer << ' ' << (int)(2*x==W && 2*y==H) << endl;
  return 0;
}