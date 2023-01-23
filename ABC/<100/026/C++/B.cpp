#include<iostream>
#include<vector>
using namespace std;
typedef int64_t ll;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define fore(a, v) for(auto a : v)
void getDivisors(ll n, vector<ll> &divisors);

int main(){
  ll N; cin >> N;
  vector<ll> divs;
  getDivisors(N, divs);
  ll forCheck = -N;
  fore(div, divs) forCheck += div;
  if(forCheck == N) cout << "Perfect"   << endl;
  if(forCheck  > N) cout << "Abundant"  << endl;
  if(forCheck  < N) cout << "Deficient" << endl;
  return 0;
}

void getDivisors(ll n, vector<ll> &divisors){
  for(ll i = 1; i*i <= n; ++i){
    if(n%i == 0){
      divisors.push_back(i);
      if(i*i == n) break;
      divisors.push_back(n/i);
    }
  }
}