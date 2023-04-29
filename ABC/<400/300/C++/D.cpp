#include<iostream>
#include<vector>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

bool E[500010];

int main(){
  ll N; cin >> N;
  rep(i, 2, 500010) E[i] = true;
  rep(i, 2, 500010){
    if(E[i]){
      for(ll j = i*i; j <= 500010; j += i){
        E[j] = false;
      }
    }
  }
  vector<int> P;
  rep(i, 2, 500010)if(E[i])P.push_back(i);
  ll M = P.size();

  ll answer = 0;
  rep(ia, 0, M-1){
      rep(ib, ia+1, M){
      ll a = P[ia], b = P[ib];
      if(a*a*a > N) break;
      if(a*a*a * b > N)break;
      
      ll l = ib, r = M;
      while(l+1 < r){
        ll mid = (l + r) / 2;
        ll c = P[mid];
        if(a*a*b * c > N || a*a*b * c*c > N) r = mid;
        else l = mid;
      }
      answer += l-ib;
      
    }
  }
  cout << answer << endl;
  


  return 0;
}