#include<iostream>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

ll N, A, B;
ll P, Q, R, S;
const ll ll1 = 1;

char get_colour(ll i, ll j){
  if(abs(i - A) == abs(j - B)){
    ll k = i - A;
    if(max(ll1 - A, ll1 - B) <= k && k <= min(N - A, N - B)){
      return '#';
    }
    if(max(ll1 - A, B - N) <= k && k <= min(N - A, B - ll1)){
      return '#';
    }
  }
  
  return '.';
}

int main(){
  cin >> N >> A >> B;
  cin >> P >> Q >> R >> S;
  
  rep(i, P, Q+1){
    rep(j, R, S+1) cout << get_colour(i, j);
    cout << endl;
  }
  return 0;
}