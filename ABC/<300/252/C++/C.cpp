#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define fore(a, v) for(auto a : v)

int main(){
  int N; cin >> N;
  vector<string> S(N); rep(i,0,N) cin >> S[i];
  int answer = 1000000000+7;
  rep(i,0,10){
    map<int, int> mp;
    rep(n,0,N)rep(j,0,10)if((int)(S[n][j]-'0') == i) ++mp[j];
    int tmpmax = 0, such_j = -1;
    fore(p, mp)if(tmpmax <= p.second){tmpmax = p.second; such_j = p.first;}
    answer = min(answer, such_j + (tmpmax-1)*10);
  }
  cout << answer << endl;
  return 0;
}