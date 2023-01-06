#include<iostream>
#define rep(i, s, t) for (int i = (s); i < (t); ++i)
using namespace std;

bool isPrime(int N);
int main(){
  int X; cin >> X;
  while(true){
    if(isPrime(X)){
      cout << X << endl;
      return 0;
    }
    X += 1;
  }
}
bool isPrime(int N){
  if(N == 1) return false;
  if(N == 2) return true;
  if(N%2 == 0) return false;
  int div = 3;
  while (div * div <= N){
    if (N % div == 0) return false;
    div += 2;
  }
  return true;
}