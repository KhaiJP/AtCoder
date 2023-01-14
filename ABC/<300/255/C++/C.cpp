#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef int64_t ll;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  ll X, A, D, N; cin >> X >> A >> D >> N;
  if(D == 0){cout << abs(X-A) << endl; return 0;}
  
  if(D < 0) A = A+(N-1)*D, D = -D;
  if(A+(N-1)*D < X){cout << X-(A+(N-1)*D) << endl; return 0;}
  if(X < A)        {cout << A-X << endl;           return 0;}

  // let A+0D, A+D, A+2D, ... , A+kD, X, A+(k+1)D, ... , 
  ll k = (X-A)/D;
  ll ans = min(X-(A+k*D), A+(k+1)*D-X);
  cout << ans << endl;
  return 0;
}