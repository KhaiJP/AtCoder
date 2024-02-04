#include<iostream>
#include<map>
#include<atcoder/all>
using namespace std;
using ll = int64_t;
using mint = atcoder::modint1000000007;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

ll N;
map<string, mint> dp;
string AGCT = "AGCT";

bool appear_AGC(string s){
  return s.substr(0, 3) == "AGC" || s.substr(1,3) == "AGC";
}

string make_next(string now, char c){
  string nxt = now + c;
  
  if(appear_AGC(nxt)) return "";

  rep(i, 0, 3){
    string tmp = nxt;
    swap(tmp[i], tmp[i+1]);
    if(appear_AGC(tmp)) return "";
  }

  return nxt.substr(1);
}

int main(){
  cin >> N;
  dp["***"] = 1;

  rep(i, 0, N){
    map<string, mint> _dp;
    for(auto p : dp){
      string now = p.first;
      mint M = p.second;
      for(char c : AGCT){
        string nxt = make_next(now, c);
        if(nxt == "") continue;

        _dp[nxt] += p.second;
      }
    }
    swap(dp, _dp);
  }

  mint answer = 0;
  for(auto p : dp) answer += p.second;
  cout << answer.val() << endl;
  return 0;
}