#include<iostream>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)
#define MAX 200000

// the key is that ∀A,B ∈ N, A xor B  <= A + B
ll N, pfx_sum[MAX+10], pfx_xor[MAX+10], answer;

int main(){
  cin >> N;
  rep(i, 0, N){
    ll A; cin >> A;
    pfx_sum[i+1] = pfx_sum[i] + A;
    pfx_xor[i+1] = pfx_xor[i] ^ A;
  }

  rep(l, 1, N+1){
    ll ok = l, ng = N+1;
    while(abs(ok - ng) > 1){
      ll mid = (ok + ng) / 2;

      ll tmp_sum = pfx_sum[mid] - pfx_sum[l-1];
      ll tmp_xor = pfx_xor[mid] ^ pfx_xor[l-1];

      if(tmp_xor == tmp_sum) ok = mid;
      else                   ng = mid;
    }
    answer += ok - l + 1;
  }

  cout << answer << endl;
  return 0;
}