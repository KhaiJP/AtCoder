#include<iostream>
#include<atcoder/all>
using namespace std;
using mint = atcoder::modint1000000007;

// all_n    : all the patterns of {A} with no constraint
// xor_0_9  : all the patterns of {A} without either 0 or 9
// nand_0_9 : all the patterns of {A} with neighter 0 nor 9 
mint answer, all_n=1, xor_0_9=1, nand_0_9=1;

int main(){
  int N; cin >> N;
  for(int i = 0; i < N; ++i){
    all_n    *= 10;
    xor_0_9  *= 9;
    nand_0_9 *= 8;
  }
  answer = all_n - 2*xor_0_9 + nand_0_9;
  cout << answer.val() << endl;
  return 0;
}