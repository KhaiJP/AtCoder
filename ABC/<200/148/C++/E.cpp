#include<iostream>
#include<vector>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  vector<ll> fives;
  ll f = 5;
  while(f <= 1e18){
    fives.push_back(f);
    f *= 5;
  }

  ll N; cin >> N;

  ll answer = 0;
  for(auto five : fives) answer += (N/five) / 2;
  cout << (N & 1 ? 0 : answer) << endl;
  return 0;
}