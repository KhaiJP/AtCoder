#include<iostream>
#include<map>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

void pfactors(ll x, map<ll, ll> &m){
  while(x % 2 == 0){
    ++m[2];
    x /= 2;
  }
  for(ll n = 3; n*n <= x; n += 2){
    while(x % n == 0){
      ++m[n];
      x /= n;
    }
  }
  if(x > 1) ++m[x];
}

int main(){
  ll A, B; cin >> A >> B;
  map<ll, ll> ma, mb;
  pfactors(A, ma), pfactors(B, mb);
  
  // no merit in choosing composite numbers 
  // common divisor 1 does not appear in both ma and mb: answer is initialised by 1
  ll answer = 1;
  for(auto a : ma)if(mb.count(a.first) == 1) ++answer;
  
  cout << answer << endl;
  return 0;
}