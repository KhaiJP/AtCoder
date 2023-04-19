#include<iostream>
#include<map>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

map<int, int> m;
const ll MOD = 1000000007;

void dev(int n){
  while(n % 2 == 0){
    ++m[2];
    n /= 2;
  }
  for(int i = 3; i * i <= n; i += 2){
    while(n % i == 0){
      ++m[i];
      n /= i;
    }
  }
  if(n != 1) ++m[n];
}

int main(){
  int N; cin >> N;
  rep(i, 2, N+1) dev(i);
  
  ll answer = 1;
  for(auto p : m) answer = (answer * (p.second + 1) ) % MOD;
  cout << answer << endl;
  return 0;
}