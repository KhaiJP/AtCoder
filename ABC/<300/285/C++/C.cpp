#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
typedef int64_t ll;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  string S; cin >> S;
  reverse(S.begin(), S.end());
  ll answer = 0;
  ll twoSix = 1;
  ll N = S.size();
  rep(i,0,N){
    ll a = (ll)S[i] - 64;
    answer += twoSix*a;
    twoSix *= 26;
  }
  cout << answer << endl;
  return 0;
}