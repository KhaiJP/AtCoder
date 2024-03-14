#include<iostream>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

ll answer[55], K, k, m, N=50;

int main(){
  cin >> K;
  
  k = K / N, m = K % N;
  rep(i, 0, N) answer[i] = N-1 + k;
  rep(i, 0, m) answer[i] += N - (m-1);
  rep(i, m, N) answer[i] -= m;
  
  cout << N << endl;
  rep(i, 0, N) cout << answer[i] << endl;
  return 0;
}