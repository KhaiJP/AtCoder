#include<iostream>
using namespace std;

int main(){
  int64_t N; cin >> N;
  int64_t mod = 998244353;
  int64_t x = N%mod;
  cout << (x>=0 ? x : x+mod) << endl;
  return 0;
}