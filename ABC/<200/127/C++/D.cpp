#include<iostream>
#include<algorithm>
#include<iterator>
#include<map>
#include<unordered_map>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

// say N cards A = {A_i}_i is {A_i:n_i}_i, here n_i:A_i means A consistes of n_i A_i s
// eg A = {1, 2, 2, 3, 3, 3, 4, 4} -> {1:1, 2:2, 3:3, 4:2} 
// B_i and C_i can be  written as C_i:B_i
// after all we have {n_i:X_i}_i(decreasing order) and the answer is obtained by greedy
map<ll, ll> m;

int main(){
  ll N, M; cin >> N >> M;
  rep(i, 0, N){
    ll a; cin >> a;
    // minus sign is added to make bigger numbers forward
    ++m[-a];
  }
  rep(i, 0, M){
    ll b, c; cin >> b >> c;
    // minus sign is added to make bigger numbers forward
    m[-c] += b;
  }

  ll n = 0;

  ll answer = 0;
  for(auto p : m){
    if(n + p.second <= N){
      // p.fist is negative
      answer -= p.second * p.first;
      n += p.second;
    }else{
      // p.first is negative
      answer -= (N - n) * p.first;
      n = N;
    }
    if(n == N) break;
  }

  cout << answer << endl;
  return 0;
}