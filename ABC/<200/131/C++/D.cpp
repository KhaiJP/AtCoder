#include<iostream>
#include<algorithm>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

pair<ll, ll> P[200010];

int main(){
  ll N; cin >> N;
  rep(i, 0, N) cin >> P[i].second >> P[i].first;
  sort(P, P+N);
  
  ll tot = 0;
  rep(i, 0, N){
    tot += P[i].second;
    if(tot > P[i].first){
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
  return 0;
}