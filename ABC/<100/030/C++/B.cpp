#include<iostream>
using namespace std;

int main(){
  double h, m; cin >> h >> m;
  if(h>=12) h -= 12;
  h += m/60;
  double angle_h = 360 * h/12;
  double angle_m = 360 * m/60;
  double angle = max(angle_h, angle_m) - min(angle_h, angle_m);
  angle = min(angle, 360-angle);
  cout << angle << endl;
  return 0;
}