#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

bool isvalid(vector<int> &v){
  int t = 0;
  for(auto a : v){
    // 0 corresponds '(', 1 corresponds ')'
    t += (a == 0 ? 1 : -1);
    // t < 0 implies v is invalid () string; more ')'s appear
    if(t < 0) return false;
  }
  // t ≠ 0 -> number of '('s and ')' are not the same
  return t == 0;
}

int main(){
  int N; cin >> N;
  // N must be even to be valid
  if(N&1) return 0;

  vector<int> A(N,  0);
  // 0 corresponds '(', 1 corresponds ')'
  rep(i, N/2, N) A[i] = 1;
  do{
    if(isvalid(A)){
      for(auto a : A) cout << (a == 0 ? '(' : ')');
      cout << '\n';
    }
  }while( next_permutation(A.begin(), A.end()) );
  
  return 0;
}