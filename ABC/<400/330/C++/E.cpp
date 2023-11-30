#include<iostream>
#include<set>
#include<map>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

set<ll> S;
map<ll, ll> M;
ll N, Q, A[200010], mex;

int main(){
  cin >> N >> Q;
  rep(i, 0, N+1) S.insert(i);
  rep(i, 0, N){
    cin >> A[i];
    A[i] = min(A[i], N+1);
    ++M[A[i]];
    if(A[i] > N) continue;
    if(M[A[i]] == 1) S.erase(A[i]);
  }

  while(Q--){
    ll i, x; cin >> i >> x;
    --i;
    x = min(x, N+1);
    ll old = A[i];
    A[i] = x;

    --M[old], ++M[x];
    if(M[old] == 0){
      S.insert(old);
    }
    if(M[x] == 1){
      S.erase(x);
    }
    for(auto a : S) cout << a << ' '; cout << endl;
    cout << *S.begin() << endl;
  }

  return 0;
}