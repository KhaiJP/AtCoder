#include<iostream>
#include<vector>
#define rep(i,s,t) for(int i=(s); i<(t); ++i)
using namespace std;
int main(){
  int32_t N; cin >> N;
  vector<uint32_t> A(N);
  rep(i,0,N) cin >> A[i];
  int64_t B;
  rep(i,0,N){
    if(i%2==0) B += A[i];
    else B -= A[i];
  }
  cout << B << " ";
  rep(i,1,N){
    B = 2*A[i-1] - B;
    cout << B << " ";
  }
  cout << endl;
  return 0;
} 