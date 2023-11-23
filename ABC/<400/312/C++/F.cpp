#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

ll N, M, answer, A[200010], B[200010], pfxA[200010], pfxB[200010], l;
priority_queue<ll> p, q;

int main(){
  cin >> N >> M;
  rep(i, 0, N){
    ll T, X; cin >> T >> X;
    if(T == 0) A[i] = X;
    if(T == 1) q.push({X});
    if(T == 2) p.push(X);
  }
  sort(A, A+N, greater<ll>());
  rep(i, 0, M) pfxA[i+1] = pfxA[i] + A[i];

  ll idx = 0;
  while(q.size() && idx < M){
    ll X = q.top();
    q.pop();
    if(l == 0){
      if(p.size() == 0) break;
      B[idx] = 0;
      ++idx;
      l = p.top();
      p.pop();
    }
    if(idx >= M) break;
    B[idx] = X;
    --l;
    ++idx;
  }
  rep(i, 0, M) pfxB[i+1] = pfxB[i] + B[i];

  rep(i, 0, M+1) answer = max(answer, pfxA[i] + pfxB[M-i]);
  cout << answer << endl;
  return 0;
}