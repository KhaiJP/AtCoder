#include<iostream>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)
#define ll1 (ll)1

ll rec(ll level, ll x){
  if(level == 0) return 1;
  if(x == 1) return 0;

  ll length = (ll1 << (level + 1)) - 3;
  ll num = (ll1 << level) - 1;

  if(x <= length + 1) return rec(level - 1, x - 1);
  else if(x <= length + 2) return num + 1;
  else if(x <= (length + 1) * 2) return num + 1 + rec(level - 1, x - length - 2);
  else return 2 * num + 1;
}

int main(){
  ll N, X; cin >> N >> X;
  cout << rec(N, X) << endl;
  return 0;
}