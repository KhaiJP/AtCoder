#include<iostream>
#include<map>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

ll A[200010];

int main(){
  ll N; cin >> N;
  rep(i, 0, N) cin >> A[i];

  map<ll, ll> count;

  ll answer = 0;
  rep(i, 0, N){
    answer +=  count[i - A[i]];
    ++count[i + A[i]];
  }

  cout << answer << endl;
  return 0;
}