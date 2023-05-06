#include<iostream>
#include<map>
using namespace std;
using ll = int64_t;

map<ll, ll> m;

void div(ll n){
  while(n % 2 == 0){
    ++m[2];
    n /= 2;
  }

  for(ll i = 3; i*i <= n; i += 2){
    while(n % i == 0){
      ++m[i];
      n /= i;
    }
  }

  if(n > 1) ++m[n];
}

int main(){
  ll N, P; cin >> N >> P;
  div(P);

  ll answer = 1;
  for(auto &p : m){
    while(p.second >= N){
      answer *= p.first;
      p.second -= N;
    }
  }

  cout << answer << endl;
  return 0;
}