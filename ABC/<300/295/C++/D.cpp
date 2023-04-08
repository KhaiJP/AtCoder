#include<iostream>
#include<string>
#include<map>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  string S; cin >> S;

  map<int, ll> m;
  int ref = 0;
  ++m[ref];
  for(char c : S){
    int nc = c - '0';
    ref = ref ^ (1 << nc);
    ++m[ref];
  }

  ll answer = 0;
  for(auto p : m){
    ll &a = p.second;
    answer += a * (a - 1) / 2;
  }

  cout << answer << endl;
  return 0;
}