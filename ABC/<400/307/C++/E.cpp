#include <atcoder/all>
#include <iostream>
using namespace std;
using namespace atcoder;
using mint = modint998244353;
#define rep(i, s, t) for (int i = (s); i < (t); ++i)
#define SAME 1
#define DIFF 0

int N, M;
// dp[i][j] : # of patterns distributed up to person i with;
//            1) the number given to i is same as the number to 1 (j = SAME)
//            2) the number given to i is diff to the number to 1 (j = DIFF) 
mint dp[1000010][2], answer;

int main() {
  cin >> N >> M;

  // in the case there is only person 1, then the fitst person and the last always have the same number
  dp[1][SAME] = M;
  rep(i, 1, N) {
    // person i+1 has no choise but choose the number person 1 owns
    // -> dp[i+1]  += 1 * dp[i][DIFF]
    dp[i+1][SAME]  += dp[i][DIFF];
    // from dp[i][DIFF] -> person i+1 has M-2 chices; 0 to M-1
    // excluding the number person 1 owns and the number preson i owns
    dp[i+1][DIFF]  += (M - 2) * dp[i][DIFF];
    // from dp[i][DIFF] -> person i+1 has M-2 chices; 0 to M-1
    // excluding the number person 1 owns = the number preson i owns
    dp[i+1][DIFF]  += (M - 1) * dp[i][SAME];
  }

  cout << dp[N][DIFF].val() << endl;
  return 0;
}