#include<iostream>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

string X;
ll M, ll1 = 1;

bool isOK(ll m){
  ll tmp = 0;
  for(char c : X){
    if(tmp > M/m) tmp = M+1;
    else          tmp = tmp * m + (c - '0');
  }

  return tmp <= M;
}

int main(){
  cin >> X >> M;

  if(X.size() == 1){
    cout << ( stoi(X) <= M ? 1 : 0 ) << endl;
    return 0;
  }

  ll d = 0; for(char c : X) d = max(d, (ll)(c - '0'));

  ll l = d, r = M+1;
  while(l+1 < r){
    ll mid = (l + r) / 2;
    if(isOK(mid)) l = mid;
    else          r = mid;
  }

  cout << l - d << endl;
  return 0;
}