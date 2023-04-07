#include<iostream>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

ll A[100010], pfx[100010];

int main(){
  ll N, K; cin >> N >> K;
  rep(i, 1, N+1) cin >> A[i];
  rep(i, 1, N+1) pfx[i] = pfx[i-1] + A[i];
  // answer = (total number of subsequences) - (number of subsequences whose sum < K)
  // the total number = N + N-1 + ... + 1 = N * (N - 1) / 2
  ll tot = N * (N + 1) / 2;

  // two pointers
  ll r = 1, numLessK = 0;
  rep(l, 1, N+1){
    while(r <= N && pfx[r] - pfx[l-1] < K) ++r;
    numLessK += r - l;
  }

  cout << tot - numLessK << endl;
  return 0;
}