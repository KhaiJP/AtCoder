#include<iostream>
#include<vector>
typedef int64_t ll;
#define rep(i,s,t) for(ll i=(s); i<(t); ++i)
using namespace std;

int main(){
  ll N, M; cin >> N >> M;
  vector<ll> pfx_ord(N+1, 0), pfx_spc(N+1, 0);
  rep(i,1,N+1){
    ll Ai; cin >> Ai;
    pfx_ord[i] = pfx_ord[i-1] + Ai;
    pfx_spc[i] = pfx_spc[i-1] + i*Ai;
  }
  ll answer = -100000000000000000000;
  // let B_1 = A_i, then 
  // ∑_{j=1}^M j*B_j = ∑_{j=i}^{i+M-1} (j-i+1)A_j
  //                 = ∑_{j=i}^{i+M-1} j*A_j - ∑_{j=i}^{i+M-1} (i-1)A_j
  //                 = ( ∑_{j=0}^{i+M-1} j*A_j - ∑_{j=0}^{i-1} j*A_j ) - (i-1)( ∑_{j=1}^{i+M-1}A_j - ∑_{j=1}^{i-1}A_j )
  //                 = ( pfx_spc[i+M-1] - pfx_spc[i-1] )  -  (i-1)* ( pfx_ord[i+M-1] - pfx_ord[i-1] )
  // where A_0 = 0.
  rep(i,1,N-M+2) answer = max(answer, pfx_spc[i+M-1]-pfx_spc[i-1]-(i-1)*(pfx_ord[i+M-1]-pfx_ord[i-1]));
  cout << answer << endl;
  return 0;
}