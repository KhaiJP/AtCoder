#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;
typedef int64_t ll;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  ll N; cin >> N;
  unordered_set<string> histroy;
  // p.first: maximum score, p.second: its index.
  pair<ll,int> p = {-1,-1};
  rep(i,0,N){
    string S; cin >> S;
    ll T; cin >> T;
    if(histroy.count(S)==1) continue;
    if(T > p.first) p = {T, i+1};
    histroy.insert(S);
  }
  cout << p.second << endl;
  return 0;
}