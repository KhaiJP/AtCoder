#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

pair<double, double> R2[110];

int main(){
  int N; cin >> N;
  rep(i,0,N){
    double x, y; cin >> x >> y;
    R2[i] = {x, y};
  }

  double answer = 0;
  rep(r1, 0, N-1)rep(r2, r1+1, N){
    double &x1 = R2[r1].first,  &y1 = R2[r1].second;
    double &x2 = R2[r2].first,  &y2 = R2[r2].second;
    
    double l_squared = (x2-x1)*(x2-x1)  +  (y2-y1)*(y2-y1);
    answer = max(answer,  l_squared);
  }
  cout << fixed << setprecision(10) << sqrt(answer) << endl;
  return 0;
}