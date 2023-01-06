#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#define rep(i, s, t) for (int i = (s); i < (t); ++i)
using namespace std;

int main(){
  int N; cin >> N;
  vector<string> S(N+1); rep(i,1,N+1) cin >> S[i];
  unordered_map<string, int> mS;
  rep(i,1,N+1){
    cout << S[i];
    if(mS.count(S[i])==1) cout << '(' << mS[S[i]] << ')';
    mS[S[i]]++;
    cout << '\n';
  }
  return 0;
}