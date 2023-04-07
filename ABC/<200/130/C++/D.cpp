#include<iostream>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

ll A[100010];

int main(){
  ll N, K; cin >> N >> K;
  rep(i, 0, N) cin >> A[i];

  // answer = (total number of subsequences) - (number of subsequences whose sum < K)
  // the total number = N + N-1 + ... + 1 = N * (N - 1) / 2
  ll tot = N * (N + 1) / 2;

  // two pointers
  ll l = 0, r = 0, numLessK = 0, tmpSum = 0;
  while(true){
    if(r == N){
      ++l;
      ll M = (r-1) - l + 1;
      numLessK += M * (M + 1) / 2;
      break;
    }
    
    if(tmpSum + A[r] < K){
      tmpSum += A[r];
      ++numLessK;
      ++r;
    }else if(r == l){
      ++r, ++l;
    }else{
      tmpSum -= A[l];
      ++l;
      numLessK += (r-1) - l + 1;
    }
  }

  cout << tot - numLessK << endl;
  return 0;
}