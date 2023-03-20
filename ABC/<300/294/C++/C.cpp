#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
int A[100010], B[100010];
int posA[100010], posB[100010];

int main(){
  int N, M; cin >> N >> M;
  rep(i, 0, N) cin >> A[i]; A[N] = 1000000001;
  rep(j, 0, M) cin >> B[j]; B[M] = 1000000001;
  int pA = 0, pB = 0;

  while(pA != N || pB != M){
    if( A[pA] < B[pB] ){
      posA[pA] = pA + pB + 1;
      ++pA;
    }
    else( B[pB] < A[pA] ){
      posB[pB] = pA + pB + 1;
      ++pB;
    }
  }

  rep(i, 0, N) cout << posA[i] << ' '; cout << '\n';
  rep(j, 0, M) cout << posB[j] << ' '; cout << endl;
  return 0;
}