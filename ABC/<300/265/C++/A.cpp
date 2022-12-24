#include<iostream>
using namespace std;

int main(){
  int X, Y, N; cin >> X >> Y >> N;
  if(3*X <= Y || N < 3){
    cout << N*X << endl;
    return 0;
  }
  int nY = N/3;
  int nX = N - 3*nY;
  cout << nX*X + nY*Y << endl;
  return 0;
}