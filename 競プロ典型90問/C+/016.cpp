#include<iostream>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

int main(){
  ll N, A, B, C; cin >> N >> A >> B >> C;

  const ll MAX = 9999;

  ll answer = MAX + 1;
  rep(nA, 0, MAX+1)rep(nB, 0, MAX+1-nA){
    ll CnC = N - (A*nA + B*nB);
    
    if(CnC >= 0 && CnC % C == 0) answer = min(answer, nA + nB + CnC/C);
  }

  cout << answer << endl;
  return 0;
}