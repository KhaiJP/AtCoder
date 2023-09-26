#include<iostream>
using namespace std;

int main(){
  int X, N = 0; cin >> X;
  while(true){
    if(N*N*N*N == X){
      cout << N << endl;
      return 0;
    }
    ++N;
  }
}