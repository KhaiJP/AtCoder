#include<iostream>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

int N, K, answer, M = 1000000007;

ll f(ll x){
  return (x*(2*N - x + 1)/2 - x*(x - 1)/2 + 1) % M; 
}

int main(){
  cin >> N >> K;
  rep(k, K, N+2) answer = (answer + f(k)) % M;
  cout << answer << endl;
  return 0;
}