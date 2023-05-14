#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define rrep(i, s, t) for(int i = (s); i >= (t); --i)

int A[100];

int main(){
  int N; cin >> N;
  rep(i, 0, N) cin >> A[i];

  cout << A[0] << ' ';
  rep(i, 0, N-1){
    if(A[i] < A[i+1]){
      rep(k, A[i]+1, A[i+1] + 1) cout << k << ' ';
    }
    
    else{
      rrep(k, A[i]-1, A[i+1]) cout << k << ' ';
    }
  }cout << endl;

  return 0;
}