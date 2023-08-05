#include<iostream>
#include<queue>
#include<unordered_set>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

ll A[11], N, K, k;

int main(){
  cin >> N >> K;
  rep(i, 0, N) cin >> A[i];
  unordered_set<ll> S;
  priority_queue<ll> q;
  rep(i, 0, N)if(S.count(A[i]) == 0){
    q.push(-A[i]);
    S.insert(A[i]);
  }
  
  while(1){
    ll p = -q.top(); q.pop();
    ++k;
    if(k == K){
      cout << p << endl;
      return 0;
    }
    rep(i, 0, N)if(S.count(p+A[i]) == 0){
      q.push(-p-A[i]);
      S.insert(p+A[i]);
    }
  }
}