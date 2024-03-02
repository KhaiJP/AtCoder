#include<iostream>
#include<algorithm>
using namespace std;
using ll = int64_t;

bool is_palindromic(ll n){
  string S, T; S = T = to_string(n);
  reverse(S.begin(), S.end());
  return S == T;
}

int main(){
  ll N; cin >> N;
  ll answer = 0;

  for(ll i = 1; i*i*i <= N; ++i){
    ll n = i*i*i;
    if(is_palindromic(n)) answer = n;
  }

  cout << answer << endl;
  return 0;
}