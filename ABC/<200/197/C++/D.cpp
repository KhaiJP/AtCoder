#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define fore(a, v) for(auto a : v)

int main(){
  double N; cin >> N;
  double x0, y0; cin >> x0 >> y0;
  double xN2, yN2; cin >> xN2 >> yN2;
  double x_org = (xN2 + x0)/2.0, y_org = (yN2 + y0)/2.0;
  double rx0 = x0 - x_org, ry0 = y0 - y_org;

  double rx1 = cos(2.0*M_PI/N)*rx0 - sin(2.0*M_PI/N)*ry0;
  double ry1 = sin(2.0*M_PI/N)*rx0 + cos(2.0*M_PI/N)*ry0;
  cout << fixed <<  setprecision(11) << rx1+x_org << ' ' << ry1+y_org << endl;
  return 0;
}