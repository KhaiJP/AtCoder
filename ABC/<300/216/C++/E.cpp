#include<iostream>
#include<algorithm>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

ll A[100010];

int main(){
  ll N, K; cin >> N >> K;
  rep(i, 0, N) cin >> A[i];
  sort(A, A + N, greater<ll>()); A[N] = 0;
  ll answer = 0;
  rep(i, 0, N){
    ll delta = A[i] - A[i+1];
    if((i + 1) * delta <= K){
      answer += (i + 1) * delta * (A[i] + (A[i+1] +1)) / 2;
      K -= (i + 1) * delta;
    }else{
      delta = K / (i + 1);
      answer += (i + 1) * (delta * (A[i] + (A[i] - delta + 1)) / 2 );
      K -= delta * (i + 1);
      answer += (A[i] - delta) * K;
      break;
    }
  }

  cout << answer << endl;
  return 0;
}