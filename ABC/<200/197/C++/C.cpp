#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
typedef int64_t ll;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)
#define fore(a, v) for(auto a : v)

void binexpansion(ll n, vector<ll> &v);

int main(){
  ll N; cin >> N;
  vector<ll> A(N); rep(i,0,N) cin >> A[i];
  ll answer = 1000000000000000000;

  rep(i,0,(1<<(N-1))){
    //if i = 25 = 0b11001 -> v = {0,3,4}
    vector<ll> V; binexpansion(i,V);

    // if i = 25, S[0] = {A0, ... , A3}, S[1] = {A4}, S[2] = {A5, ... , AN-1}
    map<ll, vector<ll>> S;
    ll index = 0;
    rep(j,0,N){
      S[index].push_back(A[j]);
      if(find(V.begin(), V.end(), j) != V.end()) ++index;
    }

    // ORs[j] = OR(S[j])
    vector<ll> ORs(S.size()+1);
    fore(p,S){
      ll ind = p.first;
      vector<ll> &v = p.second;
      ORs[ind] = v[0];
      rep(k, 1, v.size()){
        ORs[ind] = ORs[ind] | v[k];
      }
    }

    // XOR = XOR(ORs)
    ll XOR = ORs[0];
    rep(k,1,ORs.size()) XOR = XOR ^ ORs[k];
    answer = min(answer, XOR);
  }
  cout << answer << endl;
  return 0;
}

void binexpansion(ll n, vector<ll> &v){
  ll index = 0;
  while(n > 0){
    if(n%2==1) v.push_back(index);
    ++index;
    n /= 2;
  }
}