#include<iostream>
#include<map>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

map<ll, ll> schedule;

int main(){
  ll N, K; cin >> N >> K;
  ll num_pills = 0;
  rep(i, 0, N){
    ll a, b; cin >> a >> b;
    num_pills += b;
    schedule[a+1] += b;
  }
  schedule[1] = 0;

  for(auto p : schedule){
    ll day = p.first, delta = p.second;
    num_pills -= delta;
    if(num_pills <= K){
      cout << day << endl;
      return 0;
    }
  }
}