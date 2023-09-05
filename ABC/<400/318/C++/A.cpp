#include<iostream>
using namespace std;

int main(){
  int N, M, P; cin >> N >> M >> P;
  cout << ( N >= M ? (N - M) / P + 1 : 0 ) << endl;
  return 0;
}