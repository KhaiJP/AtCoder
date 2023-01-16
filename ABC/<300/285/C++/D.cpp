#include<iostream>
#include<unordered_map>
#include<string>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)


int main(){
  int N; cin >> N;
  unordered_map<string, int> mp;
  int kinds = 0;
  dsu uf(2*N);
  rep(i,0,N){
    string S, T; cin >> S >> T;
    int nS, nT; // int expression of S and T
    // check if S is already appeared and set nS
    if(mp.count(S) == 1) nS = mp[S];
    else{
      nS = kinds;
      mp[S] = nS;
      ++kinds;
    }
    // check if T is already appeared and set nT
    if(mp.count(T) == 1) nT = mp[T];
    else{
      nT = kinds;
      mp[T] = nT;
      ++kinds;
    }
    // check if cyclic
    if(uf.same(nS,nT)){
      cout << "No" << endl;
      return 0;
    }
    uf.merge(nS,nT);
  }
  cout << "Yes" << endl;
  return 0;
}
