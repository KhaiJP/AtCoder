#include<iostream>
#include<vector>
#include<set>
using namespace std;
typedef int64_t ll;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  int N, W; cin >> N >> W;
  vector<ll> A(N); rep(i,0,N) cin >> A[i];
  set<ll> s;
  rep(i,0,N){
    if(A[i] <= W) s.insert(A[i]);
    else continue;
    rep(j,i+1,N){
      if(A[i]+A[j] <= W) s.insert(A[i]+A[j]);
      else continue;
      rep(k,j+1,N){
        if(A[i]+A[j]+A[k] <= W) s.insert(A[i]+A[j]+A[k]);
      }
    }
  }
  cout << s.size() << endl;
  return 0;
}