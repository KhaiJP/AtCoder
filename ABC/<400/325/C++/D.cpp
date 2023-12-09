#include<bits/stdc++.h>
using namespace std;
using ll = int64_t; 
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

ll N, ct, answer, latest, idx;
pair<ll, ll> S[200010];
priority_queue<ll> q;

void get_input(){
  cin >> N;
  rep(i, 0, N){
    ll T, D; cin >> T >> D;
    S[i] = {T, T+D};
  }sort(S, S+N);
}

void solve(){
  for(ll t = 0; true; ++t){
    if(q.empty()){
      if(idx == N) break;
      t = S[idx].first;
    }
    while(idx < N && S[idx].first == t){
      q.push(-S[idx].second);
      ++idx;
    }
    while(q.size() && -q.top() < t) q.pop();
    if(q.size()){
      q.pop();
      ++answer;
    }
  }
}

int main(){
  get_input();
  solve();
  cout << answer << endl;
  return 0;
}