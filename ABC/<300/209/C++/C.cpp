#include<iostream>
#include<algorithm>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

ll N, C[200010], answer=1, mod=1e9+7;

int main(){
  cin >> N;
  rep(i, 0, N) cin >> C[i];
  sort(C, C+N);
  rep(i, 0, N){
    answer = (answer * (C[i] - i)) % mod;
  }

  cout << answer << endl;
  return 0;
}