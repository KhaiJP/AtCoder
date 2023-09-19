#include<iostream>
using namespace std;
using ll = int64_t;

ll N, answer, f[10000010];

int main(){
  cin >> N;
  for(ll K = 1; K <= N; ++K){
    for(ll q = 1; q*K <= N; ++q) ++f[q*K];
    answer += K * f[K];
  }
  cout << answer << endl;
  return 0;
}