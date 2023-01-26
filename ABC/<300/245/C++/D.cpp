#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define rrep(i, s, t) for(int i = (s); i >= (t); --i)
#define fore(a, v) for(auto a : v)

int A[110], B[110], C[220], TMP[110];

int main(){
  int N, M; cin >> N >> M;
  rep(i,0,N+1) cin >> A[i];
  rep(i,0,N+M+1) cin >> C[i];
  
  // naive Polynomial Long Division
  rrep(n, N, 0) TMP[n] = C[M+n]; 
  rrep(m, M, 0){
    B[m] = TMP[N]/A[N];
    rrep(n, N, 1) TMP[n] = TMP[n-1] - B[m]*A[n-1];
    if(m > 0) TMP[0] = C[m-1]; 
  }
  rep(m,0,M+1) cout << B[m] << ' '; cout << endl;
  return 0;
}