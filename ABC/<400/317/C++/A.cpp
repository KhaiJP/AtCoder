#include<iostream>
using namespace std;

int main(){
  int N, H, X; cin >> N >> H >> X;
  for(int i = 1; i <= N; ++i){
    int P; cin >> P;
    if(H + P >= X){
      cout << i << endl;
      return 0;
    }
  }
}