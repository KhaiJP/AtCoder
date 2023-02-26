#include<iostream>
#include<vector>
#include<map>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define fore(a, v) for(auto a : v)

// got[i] : if skill i is already learnt
bool got[200010];
// tm[i] : required time to learn skill i
ll tm[200010];
// requirements[i] : skills to be learnt to learn skill i
map<ll, vector<ll>> requirements;

ll solve(ll skill){
  ll ans = 0;
  // check all the skills to learn the "skill"
  fore(subskill, requirements[skill]){
    if(!got[subskill]) ans += solve(subskill);
  }

  got[skill] = true;
  return ans + tm[skill];
}

int main(){
  int N; cin >> N;
  
  // set all the requirements
  rep(i, 1, N+1){
    ll T, K; cin >> T >> K;
    tm[i] = T;
    vector<ll> requirement(K);
    rep(j, 0 , K) cin >> requirement[j];
    requirements[i] = requirement;
  }

  cout << solve(N) << endl;
  return 0;
}