#include<iomanip>
#include<iostream>
#include<cmath>
using namespace std;

int main(){
  double H; cin >> H;
  cout << fixed << setprecision(10) << sqrt(H*(12800000+H)) << endl;
}