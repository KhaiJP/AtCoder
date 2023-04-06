#include<iostream>
using namespace std;
using ull = uint64_t;

int main(){
  ull N; cin >> N;
  ull answer = 0;

  for(ull A = 1; A*A*A <= N; ++A){
    for(ull B = A; A*B*B <= N; ++B){
      answer += (N/A)/B - (B - 1);
    }
  }

  cout << answer << endl;
  return 0;
}