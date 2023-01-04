#include<iostream>
#include<vector>
using namespace std;

int main(){
  int N, S, T, W; cin >> N >> S >> T >> W;
  vector<int> A(N); for(int i=1; i<N; ++i) cin >> A[i];
  int answer = 0;
  for(int i = 0; i < N; ++i){
    W += A[i];
    if(S <= W && W <= T) answer += 1;
  }
  cout << answer << endl;
  return 0;
}