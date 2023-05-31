#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int C[510], S[510], F[510], answer[510];

int main(){
  int N; cin >> N;
  rep(i, 1, N) cin >> C[i] >> S[i] >> F[i];
  
  rep(i, 1, N){
    int ct = 0; // current time
    int j = i;
    while(j < N){
      if(ct <= S[j]) ct = S[j];
      if(ct % F[j] != 0) ct += F[j] - ct % F[j];
      ct += C[j];
      ++j;
    } 
    answer[i] = ct;
  }

  rep(i, 1, N+1) cout << answer[i] << endl;
  return 0;
}