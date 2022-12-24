#include<iostream>
#include<vector>
#define rep(i, s, t) for(int i=(s); i<(t); ++i)
using namespace std;

int main(){
  int N; cin >> N;
  vector<int> A(N); rep(i,0,N) cin >> A[i];
  int Q; cin >> Q;
  // naive solution
  rep(i,0,Q){
    int check; cin >> check;
    if(check == 1){
      int k, x; cin >> k >> x;
      A[k-1] = x;
    }else if(check == 2){
      int k; cin >> k;
      cout << A[k-1] << endl;
    }
  }
  return 0;
}