#include<iostream>
#include<algorithm>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define chmin(a, b) a = min(a, b)

int N, M, A[200010], now, answer, k;

int main(){
  cin >> N >> M;
  k = N;

  // consider there are N+2 squares, from 0 to N+1,
  // and 0-th and N+1-th squares are painted in blue
  A[0] = 0, A[M+1] = N+1;
  rep(i , 1, M+1) cin >> A[i];
  sort(A, A+M+2);
  
  // k is the shortest positive interval between blue squares
  rep(i, 1, M+1)if(A[i-1] != A[i]-1) chmin(k, A[i]-A[i-1]-1); 
  rep(i, 1, M+2)if(A[i-1] != A[i]-1) answer += (A[i]-A[i-1]-1 + k - 1) / k;
  
  cout << answer << endl;
  return 0;
}
