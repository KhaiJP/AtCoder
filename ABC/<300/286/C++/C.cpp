#include<iostream>
#include<string>
using namespace std;
typedef int64_t ll;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)
const int64_t pInf64 =  1000000000000000000;

int main(){
  ll N, A, B; cin >> N >> A >> B;
  string S; cin >> S;

  int limit = N;
  ll answer = pInf64;
  // brute-force
  rep(n,0,limit){ // n corresponds to number of rotations
    int num_diff = 0;
    rep(j,0,limit/2) if(S[j+n] != S[N-1-j])++num_diff;
    answer = min(answer, n*A+num_diff*B);
    // rotate-like operation
    S += S[n];
    ++N;
  }
  cout << answer << endl;
  return 0;
}