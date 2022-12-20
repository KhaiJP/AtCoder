#include<iostream>
#include<vector>
#define rep(i,s,t) for(int i=(s); i<(n); ++i)
using namespace std;

int pow5(int64_t n){
  return n*n*n*n*n;
}

int main(){
  int64_t X; cin >> X;
  int64_t maxA = 0;
  while(pow5(maxA)-pow5(maxA-1)<X) ++maxA;
  for(int64_t A = maxA; A >= 0; --A){
    for(int64_t B = A-1; B>=-(maxA+1); --B){
      if(pow5(A) - pow5(B) == X){
        cout << A << ' ' << B << endl;
        return 0;
      }
    }
  }
}