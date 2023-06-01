#include<iostream>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

ll pfx[100010];

int main(){
  int N, K; cin >> N >> K;

  rep(i, 0, N){
    int a; cin >> a;
    pfx[i+1] = pfx[i] + a;
  }

  ll answer = 0;
  rep(i, K, N+1) answer += pfx[i] - pfx[i-K];

  cout << answer << endl;
  return 0;
}