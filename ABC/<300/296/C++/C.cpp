#include<iostream>
#include<set>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

// A_i - A_j = X  <-->  A_i = A_j + X
// ∃i A_i ∈ {A_j+X}_j  <--> Yes
ll A[200010];

int main(){
  ll N, X; cin >> N >> X;

  set<ll> logger;
  rep(i, 0, N){
    cin >> A[i]; 
    logger.insert(A[i] + X);
  }
  rep(i, 0, N)if(logger.count(A[i]) == 1){
    cout << "Yes" << endl;
    return 0;
  }
  cout << "No" << endl;
  return 0;
}