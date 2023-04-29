#include<iostream>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

int main(){
  ll x; cin >> x;
  ll answer = 2 * (x/11);
  x %= 11;
  if(x){
    x -= 6;
    answer += 1 + (x > 0);
  }

  cout << answer << endl;
  return 0;
}