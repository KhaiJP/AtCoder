#include<iostream>
using namespace std;

int main(){
  int K; cin >> K;
  int H = (K>=60) ? 22 : 21;
  int M = (K>=60) ? K-60 : K;
  cout << H << (M<10 ? ":0" : ":") << M << endl;
  return 0;
}