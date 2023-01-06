#include<iostream>
#include<vector>
using namespace std;
#define rep(i, s, t) for (int i = (s); i < (t); ++i)

int main(){
  int N, K, R, S, P; cin >> N >> K >> R >> S >> P;
  string T; cin >> T;
  int answer = 0;
  rep(k,0,K){
    char prev1 = 'a', prev2 = 'a';
    for(int i = k; i < N; i += K){
      if(T[i] ==  prev1 && T[i] != prev2){
        prev2 = prev1;
        prev1 = 'a'; 
        continue;
      }
      if(T[i] == 'r') answer += P;
      if(T[i] == 'p') answer += S;
      if(T[i] == 's') answer += R;
      prev2 = prev1;
      prev1 = T[i];
    }
  }
  cout << answer << endl;
  return 0;
}