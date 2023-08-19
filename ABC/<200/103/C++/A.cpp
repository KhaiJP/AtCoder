#include<iostream>
#include<algorithm>
using namespace std;

int A[3];

int main(){
  cin >> A[0] >> A[1] >> A[2];
  sort(A, A+3);
  cout << A[2] - A[0] << endl;
  return 0;
}