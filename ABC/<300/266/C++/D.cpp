#include<iostream>
#include<vector>
#include<unordered_map>
#define rep(i, s, t) for (int i = (s); i < (t); ++i)
using namespace std;
typedef int64_t ll;
typedef pair<ll, ll> pr;

int main(){
  int N; cin >> N;
  unordered_map<ll, pr> um;
  ll T, X, A;
  rep(i,0,N){
    cin >> T >> X >> A;
    um[T] = {X, A};
  }
  const int M = 100000;
  vector DP(5, vector<ll>(M+1, -1));
  DP[0][0] = 0;
  rep(t,0,M){
    ll x = -10, a=0;
    if(um.count(t+1)==1){
      x = um[t+1].first;
      a = um[t+1].second;
    }
    rep(p,0,5){
      if(DP[p][t]==-1)continue;
      rep(q,0,5) if(abs(p-q)<=1) DP[q][t+1] = max(DP[q][t+1], DP[p][t]);
      if(abs(p-x)<=1) DP[x][t+1] = max(DP[x][t+1], DP[p][t]+a);
    }
  }
  ll answer = 0;
  rep(p,0,5) answer = max(answer, DP[p][M]);
  cout << answer << endl;
  return 0;
}