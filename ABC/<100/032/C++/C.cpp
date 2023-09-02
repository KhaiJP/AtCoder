#include<iostream>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

ll s[100010], N, K;

int main(){
  cin >> N >> K;
  rep(i, 0, N) cin >> s[i];
  rep(i, 0, N)if(s[i] == 0){
    cout << N << endl;
    return 0;
  }

  ll answer = 0, r = 0, prod = 1;
  rep(l, 0, N){
    if(r < l){
      prod = 1;
      r = l;
    }
    while(prod * s[r] <= K && r < N){
      prod *= s[r];
      ++r;
    }
    answer = max(answer, r-l);
    prod /= s[l];
  }

  cout << answer << endl;
  return 0;
}