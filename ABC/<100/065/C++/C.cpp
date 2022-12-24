#include<iostream>
#define rep(i,s,t) for(int64_t i=(s); i<(t); ++i)
using namespace std;

int main(){
  int64_t N, M; cin >> N >> M;
  const int mod = 1e9 + 7;
  if(abs(N-M)>1){
    cout << 0 << endl;
    return 0;
  }
  if(N==M){
    int64_t ftl = 1; // factorial
    rep(i, 1, N+1) ftl = (ftl*i)%mod;
    cout << (ftl*ftl*2)%mod << endl;
    return 0; 
  }else{
    int64_t ftlN = 1, ftlM = 1;
    rep(i, 1, N+1) ftlN = (ftlN*i)%mod;
    rep(i, 1, M+1) ftlM = (ftlM*i)%mod;
    cout << (ftlN*ftlM)%mod;
    return 0;
  }
}