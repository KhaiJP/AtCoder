#include<iostream>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

// NM[0] = N, NM[1] = M, pfs[k][i] = required time to read i books from stack k
ll NM[2], K, answer, pfx[2][200010];

int main(){
  cin >> NM[0] >> NM[1] >> K;
  rep(k, 0, 2)rep(i, 0, NM[k]){
    ll x; cin >> x;
    pfx[k][i+1] = pfx[k][i] + x;
  }
  // safe guard for binary search
  pfx[1][NM[1]+1] = 2e18;

  // binary search O(N logM) 
  rep(n, 0, NM[0]+1)if(pfx[0][n] <=K){
    ll l = 0, r = NM[1]+1;
    while(l+1 < r){
      ll mid = (l + r) / 2;
      if(pfx[0][n] + pfx[1][mid] <= K) l = mid;
      else r = mid;
    }
    answer = max(answer, n + l);
  }

  cout << answer << endl;
  return 0;
}