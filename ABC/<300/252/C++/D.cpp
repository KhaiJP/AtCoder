#include<iostream>
#include<vector>
#define rep(i,s,t) for(int i=(s); i<(t); ++i)
using namespace std;

int main(){
  int64_t N, X; cin >> N >> X;
  vector<int64_t> A(N), B(N); rep(i,0,N) cin >> A[i] >> B[i];
  int64_t answer = 1e20;
  int64_t ref = 0;
  rep(i,0,N){
    int64_t tmp = ref + A[i] + (X-i)*B[i];
    answer = tmp < answer ? tmp : answer;
    ref += A[i] + B[i];
  }
  cout << answer << endl;
  return 0;
}