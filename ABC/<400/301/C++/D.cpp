#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

const ll ll1 = 1;

int main(){
  string S; cin >> S; reverse(S.begin(), S.end());
  ll N; cin >> N;
  ll base = 0;
  vector<ll> qmarks;

  rep(i, 0, S.size()){
    if(S[i] == '1') base += ((ll)1 << i);
    if(S[i] == '?') qmarks.push_back(i);
  }reverse(qmarks.begin(), qmarks.end());

  if(base > N){
    cout << -1 << endl;
    return 0;
  }

  for(auto pw : qmarks)if(base + (ll1 << pw) <= N) base += (ll1 << pw);

  cout << base << endl;
  return 0;
}
