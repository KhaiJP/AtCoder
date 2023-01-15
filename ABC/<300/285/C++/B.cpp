#include<iostream>
#include<string>
using namespace std;
typedef pair<int,int> pr;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  int N; cin >> N;
  string S; cin >> S;
  rep(i,1,N){
    char c = S[i];
    bool breaked = false;
    rep(k,0,N-i){
      if(S[k]==S[k+i]){cout << k << '\n'; breaked = true; break;}
    }
    if(!breaked) cout << N-i << '\n';
  }
  return 0;
}