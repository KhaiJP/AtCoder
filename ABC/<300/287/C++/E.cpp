#include<iostream>
#include<algorithm>
#include<string>
#include<unordered_map>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

string S[500010];

int main(){
  int N; cin >> N;
  unordered_map<string, int> mp;
  unordered_map<int, int> ans_map;
  rep(i, 0, N){cin >> S[i]; mp[S[i]] = i;}
  sort(S, S+N);
  rep(i,0,N){
    int ans_prev = 0, ans_next = 0;
    if(i > 0){
      rep(j,0,min(S[i].size(), S[i-1].size())){
        if(S[i][j] == S[i-1][j]) ++ans_prev;
        else break;
      }
    }
    if(i < N -1){
      rep(j,0,min(S[i].size(), S[i+1].size())){
        if(S[i][j] == S[i+1][j]) ++ans_next;
        else break;
      }
    }
    ans_map[mp[S[i]]] = max(ans_prev, ans_next);
  }
  
  rep(i,0,N) cout << ans_map[i] << '\n';
  return 0;
}