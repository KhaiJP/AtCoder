#include<iostream>
using namespace std;
using ll = int64_t;

int main(){
  ll A, B, N; cin >> A >> B >> N;
  cout << A * min(B-1, N) / B << endl;
  return 0;
}