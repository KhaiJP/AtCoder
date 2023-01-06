#include<iostream>
#include<vector>
#define rep(i,s,t) for(int i=(s); i<(t); ++i)
using namespace std;

int main(){
  int64_t N, X; cin >> N >> X;
  vector<int64_t> A(N+1,0), B(N+1,0); rep(i,1,N+1) cin >> A[i] >> B[i];
  int64_t answer = 1e20, elapsed_time = 0;
  rep(i,1,N+1){
    int64_t play_time = elapsed_time + A[i] + X*B[i];
    answer = play_time < answer ? tmp : answer;
    elapsed_time += A[i] + B[i];
    X -= 1;
    if(X==0) break;
  }
  cout << answer << endl;
  return 0;
}