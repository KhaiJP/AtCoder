#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
#define rep(i, s, t) for(int i = (s); i <(t); ++i)

pair<string, int> S[500010];
int answer[500010];

int calculate_LCP(string s, string t){
  int ul = min(s.size(), t.size());
  
  int lcp = 0;
  rep(i, 0, ul){
    if(s[i] == t[i]) ++lcp;
    else break;
  }

  return lcp;
}

int main(){
  int N; cin >> N;
  rep(i, 0, N){
    string s; cin >> s;
    S[i] = {s, i};
  }sort(S, S+N);

  rep(i, 0, N){
    if(i > 0){
      answer[S[i].second] = max(answer[S[i].second], calculate_LCP(S[i].first, S[i-1].first));
    }
    if(i < N-1){
      answer[S[i].second] = max(answer[S[i].second], calculate_LCP(S[i].first, S[i+1].first));
    }
  }

  rep(i, 0, N) cout << answer[i] << '\n';
  cout << endl;
  return 0;
}