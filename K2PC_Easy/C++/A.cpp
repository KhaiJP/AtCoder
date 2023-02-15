#include<iostream>
using namespace std;

int main(){
  int a, b, c, N; cin >> a >> b >> c >> N;
  cout << max(N-a, 0) << ' ' << max(2*N-b, 0) << ' ' << max(3*N-c, 0) << endl;
  return 0;
}