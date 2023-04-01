#include<iostream>
#include<string>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

// Let us consider representing the situation of N people in run-length encoding;
// LRLRRL -> L1 R1 L1 R2 L1
// In this case, each group consists of its size-1 happy guys and 1 unhappy guy.
// Hence the total number of happy guys is N - number_of_groups
// Single rotation make of a group makes 3 groups into 1 if whole_nuber_of_groups > 2 

int main(){
  int N, K; cin >> N >> K;
  string S; cin >> S;
  S += 'e'; // whatever other than L or R
  char ref = S[0];

  int n_groups = 0;
  rep(i, 0, N+1)if(S[i] != ref){
    ++n_groups;
    ref = S[i];
  }

  rep(k, 0, K){
    if(n_groups >= 3) n_groups -= 2;
    else if(n_groups == 2) n_groups = 1;
    else break;
  }

  cout << N - n_groups << endl;
  return 0;
}