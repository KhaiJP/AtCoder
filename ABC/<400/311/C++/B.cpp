#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int schedule[110];

int main(){
  int N, D; cin >> N >> D;
  rep(i, 0, N){
    string S; cin >> S;
    rep(j, 0, D){
      schedule[j] += S[j] == 'o';
    }
  }
  int answer = 0;
  
  rep(i, 0, D){
    int j = i;
    while(j < D && schedule[j] == N) ++j;
    answer = max(answer, j-i);
  }
  
  cout << answer << endl;
  return 0;
}