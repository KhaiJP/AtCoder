#include<iostream>
#include<vector>
typedef int64_t ll;
#define rep(i,s,t) for(ll i=(s); i<(t); ++i)
using namespace std;

int main(){
  ll N, M, T; cin >> N >> M >> T;
  vector<int> A(N); rep(i,1,N) cin >> A[i];
  rep(i, 1, M+1){
    int X; cin >> X;
    ll Y; cin >> Y;
    A[X] -= Y;
  }
  rep(i, 1, N){
    if(T > A[i]) T -= A[i];
    else{
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}