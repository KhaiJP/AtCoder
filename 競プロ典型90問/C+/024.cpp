#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int A[1010], B[1010];

int main(){
  int N, K; cin >> N >> K;
  rep(i, 0, N) cin >> A[i];
  rep(i, 0, N) cin >> B[i];

  int total_gap = 0;
  rep(i, 0, N) total_gap += abs(A[i] - B[i]);
  
  if(total_gap > K){
    cout << "No" << endl;
    return 0;
  }

  // if total_gap and K are both odd or both even, then yes
  cout << ( (total_gap ^ K) & 1 ? "No" : "Yes" ) << endl;
  return 0;
}