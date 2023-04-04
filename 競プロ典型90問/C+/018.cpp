#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

const double PI = 3.14159265359;

int main(){
  double T; cin >> T;
  double L, X, Y; cin >> L >> X >> Y;

  cout << fixed << setprecision(10);
  int Q; cin >> Q;
  while(Q){
    double E; cin >> E;

    // the angle in radian that E869120 stands
    double E_angle_rad = E/T * 2 * PI;
    // coordinates of E869120
    double Ey = -L/2 * sin(E_angle_rad), Ez = L/2 * (1 - cos(E_angle_rad));
    // coordinate gaps between the statue and E869120
    double delx = X - 0, dely = Y - Ey, delz = 0 - Ez;
    // distance on XY plain
    double delxy = sqrt(delx * delx + dely * dely);
    // the sign "-"delz/delxy is to make the angle depression
    double depression_angle_rad = atan(-delz / delxy);

    cout << depression_angle_rad * 180 / PI << '\n';

    --Q;
  }

  cout << endl;
  return 0;
}