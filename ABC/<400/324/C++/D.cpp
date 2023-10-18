#include<iostream>
#include<algorithm>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

string S;
ll N, answer, s, upper_limit = 1e7;

string _to_string(ll x){
  string T = to_string(x);
  ll t = T.size();
  rep(i, 0, max(s-t, (ll)0)) T += '0';
  sort(T.begin(), T.end());
  return T;
}

int main(){
  cin >> N >> S;
  sort(S.begin(), S.end());
  s = S.size();
  
  rep(i, 0, upper_limit){
    string T = _to_string(i * i);
    if((ll)T.size() > s) break;
    answer += S == T;
  }

  cout << answer << endl;
  return 0;
}