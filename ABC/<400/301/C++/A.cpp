#include<iostream>
#define rep(i, s, t) for(int i = (s); i < (t); ++i)


int main(){
   int N; cin >> N;
   string S; cin >> S;
  if(N == 1){
    cout << S << endl;
    return 0;
  }

  int t = 0, a = 0;
  rep(i, 0, N){
    t += S[i] == 'T';
    a += S[i] == 'A';
    if(t >= N/2){
      cout << 'T' << endl;
      return 0;
    }
    if(a >= N/2){
      cout << 'A' << endl;
      return 0;
    }
  }

  cout << (t > a ? 'T' : 'A') << endl;
  return 0;
}