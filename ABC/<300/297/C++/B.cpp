#include<iostream>
#include<string>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int B[2], R[2], K;

int main(){
  string S; cin >> S;

  int jB = 0, jR = 0;
  rep(i, 0, S.size()){
    if(S[i] == 'B'){
      B[jB] = i+1;
      ++jB;
    }
    if(S[i] == 'R'){
      R[jR] = i+1;
      ++jR;
    }
    if(S[i] == 'K') K = i+1;
  }

  bool c1 = (B[0]^B[1]) & 1;
  bool c2 = (R[0] < K && K < R[1]);
  
  cout << (c1 && c2 ? "Yes" : "No" ) << endl;
  return 0;
}