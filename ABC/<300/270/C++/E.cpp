#include<iostream>
#include<map>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

map<ll, ll> m;
ll A[100010], N, K, answer, nonzero;

int main(){
  cin >> N >> K;
  rep(i, 0, N){
    cin >> A[i];
    if(A[i]){
      ++nonzero;
      ++m[A[i]];
    }
  }
  
  // L : # of laps = pick up 1 apple from all the baskets that have 1 or more apples
  // minimum : minimum # of apples > 0 remains in a single baskect
  ll L = 0, minimum = 0;
  for(auto p : m){
    ll next = nonzero * (p.first-L);
    if(K - next <= 0){
      minimum = p.first;
      break;
    }
    K       -= next;
    nonzero -= p.second;
    L        = p.first;
  }

  // find how many laps we can have; 
  // which is greater than or equal to 0 and less than minimum
  ll l = 0, r = minimum;
  while(l+1 < r){
    ll mid = (l + r) / 2;
    ll next = nonzero * mid;
    if(K - next >= 0) l = mid;
    else             r = mid;
  }

  K -= l * nonzero;

  // find the # of apples in each basket after L + l laps of picking
  rep(i, 0, N) A[i] = max((ll)0, A[i] - (L + l));
  // pick up the remained K apples
  rep(i, 0, N)if(A[i] &&  K){
    --A[i];
    --K;
  }

  rep(i, 0, N) cout << A[i] << ' '; cout << endl;
  return 0;
}