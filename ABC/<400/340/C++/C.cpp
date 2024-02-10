#include<iostream>
#include<map>
using namespace std;
using ll = int64_t;

ll N;
map<ll, ll> memo;

ll floor(ll n){
  return n / 2;
}

ll ceil(ll n){
  // round-up division by m is given by (n + m -1) / m
  return (n+2-1) / 2;
}

ll dfs(ll n){
  if(n == 1){
    memo[n] = 0;
  }
  if(memo.count(n) == 1){
    return memo[n];
  }
  return memo[n] = n + dfs(floor(n)) + dfs(ceil(n));
}

int main(){
  cin >> N;
  cout << dfs(N) << endl;
  return 0;
}