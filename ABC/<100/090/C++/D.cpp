#include<iostream>
using namespace std;
typedef int64_t ll;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)
#define ll0 (ll)0
#define ll1 (ll)1

int main(){
  ll N, K; cin >> N >> K;

  ll answer = ll0;
  rep(b, K+1, N+1){
    answer += (N/b) * (b-K) + max(N%b - K + ll1,  ll0);
    answer -= (K == ll0 ? ll1 : ll0);
  }
  cout << answer << endl;
  return 0;
}