#include<iostream>
#include<vector>
#include<map>
#define rep(i,s,t) for(int i=(s); i<(t); ++i)
using namespace std;


int main(){
  int64_t N; cin >> N;
  // int ref = N;
  if(N==1){
    cout << 0 << endl;
    return 0;
  }
  // pfs = {K, V} = {prime_factor, order}
  map<int64_t, int64_t> pfs;
  int64_t div = 2;
  while(div*div <= N){
    while(N%div==0){
      pfs[div] +=1;
      N /= div;
    }
    div += 1;
  }
  if(N!=1) pfs[N] += 1;

  int answer = 0;
  for(auto const &pair : pfs){
    int ord = pair.second;
    int l_i = 1;
    while(ord-l_i >= 0){
      ord -= l_i;
      l_i += 1;
      answer += 1;
    }
  }
  cout << max(answer, 1) << endl;
  return 0;
}
