#include<iostream>
#include<set>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

ll N, M;
set<ll> S[200010];

int main(){
  cin >> N >> M;
  
  rep(i, 1, N+1){
    ll A; cin >> A;
    ll k = A >= 0 ? 0 : (-A+i-1)/i;
    
    rep(j, k, M+1){
      ll _A = A + j*i;
      if(_A > N) break;
      S[j].insert(_A);
    }
  }

  rep(j, 1, M+1)rep(i, 0, N+1)if(S[j].count(i) == 0){
    cout << i << endl;
    break;
  }

  return 0;
}