#include<iostream>
#include<cmath>
using namespace std;

int main(){
  int A, B; cin >> A >> B;
  cout << (int)pow(A, B) + (int)pow(B, A) << endl;
  return 0;
}