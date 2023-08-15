#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
using ll = int64_t;
using p = pair<ll,ll>;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

ll N, M, answer, L[200010], D[200010];
multiset<p> S; 
multiset<ll> P;

int main(){
  cin >> N >> M;
  rep(i, 0, N){
    ll a; cin >> a;
    P.insert(a);
    answer += a;
  }

  rep(i, 0, M) cin >> L[i];
  rep(i, 0, M) cin >> D[i];
  rep(i, 0, M) S.insert({-D[i], -L[i]});

  for(auto dl : S){
    ll d = -dl.first, l = -dl.second;
    auto itr = P.lower_bound(l);
    if(itr == P.end()) continue;
    answer -= d;
    P.erase(itr);
  }
  
  cout << answer << endl;
  return 0;
}