#include<iostream>
#include<map>
using namespace std;
using ll = int64_t;

ll N, answer, num_zeros;
map<ll, ll> cnt;

void sub_solve(ll n){
  for(ll i = 2; i*i <= n; ++i){
    ll m = i * i;
    while(n%m == 0) n /= m;
  }
  ++cnt[n];
}

int main(){
  cin >> N;
  
  for(ll i = 0; i < N; ++i){
    ll A; cin >> A;
    if(A == 0) ++num_zeros;
    else sub_solve(A);
  }

  for(auto p : cnt){
    ll n = p.second;
    answer += n * (n-1) / 2;
  }
  answer += (N - 1) * num_zeros - num_zeros * (num_zeros - 1) / 2;
  
  cout << answer << endl;
  return 0;
}