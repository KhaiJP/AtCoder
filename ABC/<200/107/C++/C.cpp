#include<iostream>
#include<vector>
using namespace std;
typedef int64_t ll;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
const int64_t pInf64 =  1000000000000000000;

int main(){
  ll N, K; cin >> N >> K;
  vector<ll> X(N); rep(i,0,N) cin >> X[i];

  ll answer = pInf64;
  rep(i,0,N-K+1){
    if(X[i]*X[i+K-1]>=0) answer = min(answer, max(-X[i], X[i+K-1]));
    else answer = min(answer, min(X[i+K-1] - 2*X[i], 2*X[i+K-1] - X[i]));
  }
  cout << answer << endl;
  return 0;
}