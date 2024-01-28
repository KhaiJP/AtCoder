#include<iostream>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

ll N, Q[11], A[11], B[11], rest[11], answer;

int main(){
  cin >> N;
  rep(i, 0, N) cin >> Q[i];
  rep(i, 0, N) cin >> A[i];
  rep(i, 0, N) cin >> B[i];

  rep(num_A, 0, 1000001){
    rep(i, 0, N) rest[i] = Q[i] - num_A * A[i];
    bool all_non_negative = true;
    rep(i, 0, N) all_non_negative = all_non_negative && (rest[i] >= 0);
    if(!all_non_negative) continue;

    ll num_B = 2000000;
    rep(i, 0, N)if(B[i] > 0) num_B = min(num_B, rest[i]/B[i]);

    answer = max(answer, num_A + num_B);
  }

  cout << answer << endl;
  return 0;
}