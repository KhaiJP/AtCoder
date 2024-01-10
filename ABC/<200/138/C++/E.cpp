#include<iostream>
#include<map>
#include<set>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

map<char, set<ll>> m;
ll ns, idx, answer;
string s, t;

int main(){
  cin >> s >> t;
  ns = s.size();
  s += s;

  rep(i, 0, 2*ns) m[s[i]].insert(i);

  for(auto c : t){
    if(m.count(c) == 0){
      cout << -1 << endl;
      return 0;
    }

    ll j = *m[c].lower_bound(idx);
    answer += j - idx + 1;
    idx = j%ns + 1;
  }

  cout << answer << endl;
  return 0;
}