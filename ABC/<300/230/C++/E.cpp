#include<iostream>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

int main(){
  ll N; cin >> N;
  
  ll sqrt = -1;
  rep(i, 1, N+1){
    if(i*i <= N) sqrt = i;
    else break;
  }

  ll answer = 0;
  rep(i, 1, sqrt+1) answer += (N/i - N/(i+1)) * i;
  rep(i, 1, N/(sqrt+1) + 1) answer += N/i;

  cout << answer << endl;
  return 0;
}