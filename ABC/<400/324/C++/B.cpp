#include<iostream>
using namespace std;
using ll = int64_t;

int main(){
  ll N; cin >> N;
  while(N%2 == 0) N /= 2;
  while(N%3 == 0) N /= 3;
  cout << (N == 1 ? "Yes" : "No") << endl;
  return 0;
}