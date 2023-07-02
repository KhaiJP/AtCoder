#include<iostream>
#include<vector>
#include<set>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

// i ∈ Ms[kM] -> A_i = kM & S_i = M, and same for Es and Xs
vector<int> Ms[3], Es[3], Xs[3];
int A[200010];

int main(){
  int N; cin >> N;
  rep(i, 0, N) cin >> A[i];
  rep(i, 0, N){
    char c; cin >> c;
    if(c == 'M') Ms[A[i]].push_back(i+1);
    if(c == 'E') Es[A[i]].push_back(i+1);
    if(c == 'X') Xs[A[i]].push_back(i+1);
  }

  ll answer = 0;
  // exhaustive search over Es[0], Es[1], Es[2]; all the indicies i st S_i = E
  rep(kE, 0, 3){
    if(Es[kE].empty()) continue;
    for(auto id : Es[kE])rep(kM, 0, 3){
      if(Ms[kM].empty()) continue;
      
      // find number of indicies i ∈ Ms[kM] st i < id -> nM
      auto itrM = lower_bound(Ms[kM].begin(), Ms[kM].end(), id);
      ll nM = distance(Ms[kM].begin(), itrM);

      if(nM > 0)rep(kX, 0, 3){
        if(Xs[kX].empty()) continue;

        // find number of indicies i ∈ Xs[kX] st i < id -> nX
        auto itrX = lower_bound(Xs[kX].begin(), Xs[kX].end(), id);
        ll nX = distance(itrX, Xs[kX].end());

        if(nX > 0){
          ll prd = nM * nX;

          // find the mex
          set<int> tmp;
          tmp.insert(kM); tmp.insert(kE); tmp.insert(kX);

          if(tmp.count(0) == 0) continue;               // mex = 0
          else if(tmp.count(1) == 0) answer += 1 * prd; // mex = 1
          else if(tmp.count(2) == 0) answer += 2 * prd; // mex = 2
          else                       answer += 3 * prd; // mex = 3
        }
      }
    }
  }

  cout << answer << endl;
  return 0;
}