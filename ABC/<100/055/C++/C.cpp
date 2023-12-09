#include<iostream>
using namespace std;
using ll = int64_t;

int main(){
  ll N, M; cin >> N >> M;
  if(N >= M/2){
    cout << M/2 << endl;
    return 0;
  }
  cout << N + (M - 2*N) / 4 << endl;
  return 0;
}