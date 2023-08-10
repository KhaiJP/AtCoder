#include<iostream>
#include<atcoder/all>
using namespace std;
using ll = int64_t;
using mint = atcoder::modint1000000007;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

// this problem is almost equivalent to the following problem;
// there are N integers Ai. each number is either 0 or 1.
// find \sum_{i,j; i!=j} Ai^Aj.
// Since 0^0 = 1^1 = 0, the answer is the number of unordered pairs {i,j} s.t. {Ai, Aj} = {0, 1}
// this number can be calculated by (# of 0s) * (# of 1s)
// the original problem can be solved by repeating the algo above 60 times
ll A[300010];

int main(){
  int N; cin >> N;
  rep(i, 0, N) cin >> A[i];
  
  mint answer = 0;
  ll b = 1;
  rep(i, 0, 60){
    // # of 0s and # of 1s
    int zeros = 0, ones = 0;
    rep(j, 0, N){
      if(A[j] & b) ++ones;
      else         ++zeros;
    }

    answer += (mint)b * zeros * ones;
    b <<= 1;
  }

  cout << answer.val() << endl;
  return 0;
}