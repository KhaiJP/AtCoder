#include<iostream>
#include<string>
using namespace std;

int main(){
  string S; cin >> S;
  int K; cin >> K;

  // two pointers method. n_p : number of '.' within [l, r)
  int l = 0,    r = 0,    n_p = 0,    answer = 0;
  while(r < S.size()){
    if(S[r] == 'X' || n_p < K){
      n_p += S[r] == '.';
      ++r;
      answer = max(answer, r - l);
    }else{
      n_p -= S[l] == '.';
      ++l;
    }
  }

  cout << answer << endl;
  return 0;
}