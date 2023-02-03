#include<iostream>
using namespace std;
using ll =  int64_t;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define fore(a, v) for(auto a : v)
#define yes "Yes"
#define noo "No"

const int MOD = 998244353;

int main(){
  ll N; cin >> N;
  int lengthN = to_string(N).size();
  
  ll answer = 0;
  ll ten = 1;
  
  rep(l, 1, lengthN){
    ten *= 10;
    ll nm = ( ten - ten/10 ) % MOD;
    ll sm = ( nm + 1 ) % MOD;
    nm%2 ? sm /= 2: nm /= 2;
    answer = ( answer +  sm * nm) % MOD;
  }

  ll delta0 = ( N - ten + 1 ) % MOD;
  ll delta1 = (delta0 + 1) % MOD;
  delta0%2 ? delta1 /= 2 : delta0 /= 2;
  answer = ( answer%MOD + ( delta0 * delta1 ) % MOD ) % MOD;

  cout << answer << endl;
  return 0;
}