#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

vector<ll> bigger, smaller;
ll N, D, P, answer1, answer2;

int main(){
  cin >> N >> D >> P;
  ll each = P / D;
  rep(i, 0, N){
    ll F; cin >> F;
    if(F > each)  bigger.push_back(F);
    else         smaller.push_back(F);
  }
  sort(bigger.begin(), bigger.end()), sort(smaller.begin(), smaller.end());
  ll sb = bigger.size();
  ll ss = smaller.size();

  ll n    = bigger.size() / D;
  ll rest = bigger.size() % D;
  answer1 = n * P;
  rep(i, 0, rest)     answer1 += bigger[i];
  for(ll a : smaller) answer1 += a;

  n       = n + 1;
  rest    = n * D - bigger.size();
  answer2 = n * P;
  
  rep(i, 0, ss - rest) answer2 += smaller[i];

  cout << min(answer1, answer2) << endl;
  return 0; 
}