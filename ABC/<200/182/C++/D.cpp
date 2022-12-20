#include<iostream>
#include<vector>
#include<numeric>
#define rep(i,s,t) for(int i=(s); i<(t); ++i)
#define ll long long
using namespace std;

int main(){
  int N; cin >> N;
  vector<ll> A(N); rep(i,0,N) cin >> A[i];
  vector<ll> pfx(N+1,0), // prefix sum
             maxUpto(N+1,0), // maximum value of prefix sum
             pseudo_pfx(N+1, 0), // the position when phase i is done
             maxSofar(N+1,0); // maximum position by the end of phase i
  ll answer = 0;
  rep(i, 1, N+1){
    pfx[i]        = pfx[i-1] + A[i-1];
    maxUpto[i]    = max(maxUpto[i-1], pfx[i]);
    pseudo_pfx[i] = pseudo_pfx[i-1] + pfx[i-1] + A[i-1];
    maxSofar[i]   = pseudo_pfx[i-1] + maxUpto[i];
    answer        = max(answer, maxSofar[i]);
  }
  cout << answer << endl;
  return 0;
}