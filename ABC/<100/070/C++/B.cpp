#include<iostream>
using namespace std;

int main(){
  int A, B, C, D; cin >> A >> B >> C >> D;
  cout << max(min(B,D) - max(A,C), 0) << endl;
  return 0;
}