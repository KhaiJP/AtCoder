#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)


int main(){
  ll N; cin >> N;
  string S; cin >> S;
  map<char, vector<ll>> m;

  rep(i, 0, N) m[S[i]].push_back(i);

  ll answer = 0;
  rep(i, 0, N-2)rep(j, i+1, N-1){
    // necessary condition
    if(S[i] == S[j]) continue;

    // determin S_k which equals neither S_i nor S_j
    char Sk;
    if(S[i] != 'R' && S[j] != 'R') Sk = 'R';
    if(S[i] != 'G' && S[j] != 'G') Sk = 'G';
    if(S[i] != 'B' && S[j] != 'B') Sk = 'B';

    // find how many ks there are that satisfy k > j
    const auto &beg = m[Sk].begin(), &ed = m[Sk].end();
    auto first_k = upper_bound(beg, ed, j);
    ll num_ks = distance(first_k, ed);

    // if one of k-s found above satisfies j - i == k - j && k > j, then such k must be omitted
    // j - i == k - j && k > j  <-->  k = 2j - i > j  <-->  j - i > 0  <--> identically true 
    if(binary_search(beg, ed, 2*j - i)) num_ks -= 1;

    answer += num_ks;
  }

  cout << answer << endl;
  return 0;
}