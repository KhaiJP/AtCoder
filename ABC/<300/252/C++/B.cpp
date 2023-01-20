#include<iostream>
#include<map>
#include<set>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  int N, K; cin >> N >> K;
  map<int, set<int>> mp;
  // best tastiness
  int M = 0;
  rep(i,0,N){
    int A; cin >> A;
    mp[A].insert(i+1);
    M = max(M, A);
  }
  rep(k,0,K){
    int B; cin >> B;
    if(mp[M].count(B) == 1){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}