#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
#define rep(i, s, t) for (ll i = (s); i < (t); ++i)

int main(){
  double a, b, d; cin >> a >> b >> d;
  double A, B;
  static const double pi = 3.141592653589793;
  double theta = pi*d/180.0;
  A = cos(theta)*a - sin(theta)*b;
  B = sin(theta)*a + cos(theta)*b;
  
  cout << fixed << setprecision(10) << A << ' ' << B << endl;
  return 0;
}