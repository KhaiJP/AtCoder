#include<iostream>
#include<vector>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

// let us consider example 3 and count # of (i,j,k) with Ai = 11.
// V_11 := {2, 8, 9, 10} = {idx | A_idx == 11 in 0-indexed representation}
// (i, k)  |  # of j that enjoys the condition
// (2, 8)  |  8 - 2 - 1 - 0 -> k - i - 1 - # of j with Ai = Aj
// (2, 9)  |  9 - 2 - 1 - 1
// (2, 10) | 10 - 2 - 1 - 2
// (8, 9)  |  9 - 8 - 1 - 0
// (8, 10) | 10 - 8 - 1 - 1
// (9, 10) | 10 - 9 - 1 - 0
// check the table above vertically, then;
// V_11[idx] is added idx times when see the left-most column.
// e.g. V_11[2] = 9 is added 2 times
// and V_11[idx] is subtracted V_11.size() - idx - 1 times when see the second left-most column.
// e.g. V_11[1] = 8 is subtracted 1 time
// and 0 is subtracted 3 = V_11.size() - 0 - 1 times, 1 is subtracted 2 = V_11.size() - 1 - 1,
// 2 is subtracted 1 = V_11.size() - 2 - 1, and 3 is subtracted 0 = V_11.size() - 3 -,
// when see the right-most column. -> V_11[idx] + idx is subtracted (V_11.size() - idx - 1) times.
// and finally -1 is operated, when see the second right-most column,
// V_11.size() * (V_11.size() - 1) / 2 times; the number of combinations

vector<ll> V_[300010];
ll N, answer;

ll count_ijk_of(vector<ll> &V){
  ll count = 0, l = V.size();
  rep(idx, 0, l){
    count += V[idx] * idx;
    count -= (V[idx] + idx) * (l - idx - 1);
  }
  count -= l * (l - 1) / 2;
  return count;
}

int main(){
  cin >> N;
  rep(idx, 0, N){
    ll A; cin >> A;
    V_[A].push_back(idx);
  }

  rep(A, 1, N+1) answer += count_ijk_of(V_[A]);
  cout << answer << endl;
  return 0;
}