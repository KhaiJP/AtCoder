#include<iostream>
#include<set>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define MAX 18

ll N, A[MAX];
set<ll> S;

int main(){
  cin >> N;
  rep(i, 0, MAX){
    ll repunit = 1;
    rep(j, 0, i) repunit = 10*repunit + 1; 
    A[i] = repunit;
  }
  rep(i, 0, MAX)rep(j, 0, MAX)rep(k, 0, MAX){
    S.insert({A[i] + A[j] + A[k]});
  }

  auto itr = S.begin();
  rep(i, 0, N-1) ++itr;
  cout << *itr << endl;
  return 0;
}