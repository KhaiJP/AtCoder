#include<iostream>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

ll T, A[10], P[10];

ll solve(){
  ll b = 2*A[1] + A[2] - A[4] - 2*A[5];
  ll candidate_1 = P[4] * b;
  ll candidate_2 = P[5] * ((b+1)/2);
  ll candidate_3 = P[4] + P[5] * (b/2);

  return max(min(candidate_1, min(candidate_2, candidate_3)), (ll)0);
}


int main(){
  cin >> T;
  while(T--){
    rep(i, 1, 6) cin >> A[i];
    rep(i, 1, 6) cin >> P[i];
    cout << solve() << endl;
  }

  return 0;
}