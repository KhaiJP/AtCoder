#include<iostream>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

// if N is odd, A must be one of the perputations of 0, 2, 2, 4, 4, ... , N-1, N-1.
// if even, 1, 1, 3, 3, 5, 5, ..., N-1, N-1.
// the actual order must be N-1, ... , 2, 0, 2, ... , N-1 (odd) or N-1, ... , 1, 1, ... , N-1 (even)
// hence the answer is 2^(N/2), or 0 iff A is not one of the permutations.

ll N, cnt[100010], answer=1, mod=1e9+7;

int main(){
  cin >> N;
  rep(i, 0, N){
    int A; cin >> A;
    ++cnt[A];
  }

  // if N is odd, only 0 emerges once
  bool f = (N&1 ? (cnt[0] == 1) : true);
  rep(i, 1, N)if((i&1) != (N&1)){
    // check if A is one of the permutations
    f = f && (cnt[i] == 2);
    // calculating 2^(N/2) mod 1e9+7
    answer = answer * 2 % mod;
  }

  cout << (f ? answer : 0) << endl;
  return 0;
}