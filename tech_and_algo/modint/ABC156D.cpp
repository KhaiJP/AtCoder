#include<iostream>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using ll = int64_t;
using mint = modint1000000007;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

mint nCk(ll n, ll k){
  mint answer = 1;
  rep(i, 0, k) answer *= (n-i);
  rep(i, 0, k) answer /= i+1;
  return answer; 
}

int main(){
  ll N, a, b; cin >> N >> a >> b;
  mint answer = mint(2).pow(N) - 1;
  answer -= nCk(N, a);
  answer -= nCk(N, b);

  cout << answer.val() << endl;
  return 0;
}