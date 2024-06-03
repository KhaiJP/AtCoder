#include<iostream>
using namespace std;

int main(){
  int N, K; cin >> N >> K;
  cout << (N - 1 + (K - 1) - 1)/(K - 1) << endl;
  return 0;
}
