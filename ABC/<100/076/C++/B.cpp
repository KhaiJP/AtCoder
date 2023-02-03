#include<iostream>
using namespace std;

int main(){
  int N, K; cin >> N >> K;
  int s = 1;
  for (int i = 0; i < N; ++i){
    if(s < K) s *= 2;
    else      s += K;
  }
  cout << s << endl;
  return 0;
}