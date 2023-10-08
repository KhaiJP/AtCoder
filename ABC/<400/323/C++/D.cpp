#include<iostream>
#include<map>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

map<ll,ll> m;
ll N, answer;

int main(){
  cin >> N;
  rep(i, 0, N){
    ll s, c; cin >> s >> c;
    while((s&1) == 0){
      s >>= 1;
      c <<= 1;
    }
    m[s] += c;
  }

  for(auto p : m){
    ll c = p.second;
    while(c){
      answer += c&1;
      c >>= 1; 
    }
  }

  cout << answer << endl;
  return 0;
}