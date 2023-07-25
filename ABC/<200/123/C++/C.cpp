#include<iostream>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define chmin(a, b) a = min((a), (b))

int main(){
  ll N, A, B, C, D, E; cin >> N >> A >> B >> C >> D >> E;
  ll M = A;
  chmin(M, B), chmin(M, C), chmin(M, D), chmin(M, E);
  cout << (N + M - 1) / M + 4 << endl;
  return 0;
}