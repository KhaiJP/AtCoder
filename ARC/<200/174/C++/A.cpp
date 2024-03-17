#include<iostream>
#include<vector>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

ll N, C, answer;

// calculating maximum/minimum subarray problem
ll Kadane(vector<ll> V, bool calc_max=true){
  ll n_local = V.size();
  ll coeff = calc_max ? 1 : -1;
  for(auto &a : V) a *= coeff;
  ll result_local = -1e18;
  ll s_local = 0;
  rep(i, 0, n_local){
    s_local = max(s_local + V[i], V[i]);
    result_local = max(result_local, s_local);
  }

  return coeff * max(result_local, (ll)0);
}

int main(){
  cin >> N >> C;
  vector<ll> A(N);
  for(ll &a : A) cin >> a;
  for(ll a : A) answer += a;
  answer += (C-1) * Kadane(A, C>0);
  cout << answer << endl;
  return 0;
}