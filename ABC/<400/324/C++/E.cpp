#include<iostream>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)
#define rrep(i, s, t) for(ll i = (s); i >= (t); --i)

ll N, t, s, answer, id;
ll L[500010], R[500010], pfx[500010];
string T, S;

int main(){
  cin >> N >> T; 
  t = T.size();
  rep(i, 0, N){
    cin >> S;
    s = S.size();
    
    id = 0;
    rep(j, 0, s){
      if(T[id] == S[j]) ++id;
      if(id == t) break;
    }
    ++L[id];

    id = 0;
    rrep(j, s-1, 0){
      if(T[t-1 - id] == S[j]) ++id;
      if(id == t) break;
    }
    ++R[id];
  }

  rrep(i, t, 0) pfx[i] = pfx[i+1] + R[i];
  rep(i, 0, t+1) answer += L[i] * pfx[t-i];
  cout << answer << endl;
  return 0;
}