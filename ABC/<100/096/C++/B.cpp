#include<iostream>
using namespace std;

int main(){
  int A, B, C, K; cin >> A >> B >> C >> K;
  if(A > B) swap(A, B);
  if(B > C) swap(B, C);
  cout << A + B + (C << K) << endl;
  return 0;
}