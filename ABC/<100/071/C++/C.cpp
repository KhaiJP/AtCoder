#include<iostream>
#include<map>
using namespace std;
typedef int64_t ll;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define fore(a, v) for(auto a : v)

int main(){
  ll N; cin >> N;
  map<ll, ll> Edges;
  ll longest = 0;
  rep(i,0,N){
    ll A; cin >> A;
    // map keys are sorted in ascending order 
    ++Edges[-A];
  }
  fore(p, Edges){
    if(p.second < 2) continue;
    if(longest != 0){
      cout << longest*p.first << endl;
      return 0;
    }
    if(longest == 0){
      longest = p.first;
      if(p.second >= 4){
        cout << longest*longest << endl;
        return 0; 
      }
    }
  }
  cout << 0 << endl;
  return 0;
}