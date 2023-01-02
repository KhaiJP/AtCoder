#include<iostream>
#include<iomanip>
using namespace std;

int main(){
  double A, B; cin >> A >> B;
  cout << fixed << setprecision(3) << B/A;
  return 0;
}