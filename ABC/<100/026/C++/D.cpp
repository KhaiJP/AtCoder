#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
#define PI (double)3.14159265359

double A, B, C, limit = (double)1/1000000000;

double f(double t){
  return A*t + B*sin(C*t*PI);
}

int main(){
  cin >> A >> B >> C;
  double ng = 0, ok = 201, val, mid;
  while(true){
    mid = (ok + ng) / 2;
    val = f(mid);
    if(abs(val - (double)100) < limit) break;
    if(val >= (double)100) ok = mid;
    else           ng = mid;
  }
  // cout << fixed << setprecision(9) << val << endl;
  cout << fixed << setprecision(14) << mid << endl;
  return 0;
}