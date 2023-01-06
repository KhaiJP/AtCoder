#include<iostream>
#include<vector>
typedef int64_t ll;
#define rep(i, s, t) for (ll i = (s); i < (t); ++i)
using namespace std;


int main(){
  ll N, X, Y; cin >> N >> X >> Y;
  ll limit = max(X,Y);
  // numX[i]: the number of jewels of level i whose color is X(= Red or Blue)
  vector<ll> numR(N+1,0), numB(N+1,0);
  numR[N] = 1;
  rep(i,1,N){
    // change Rs of level N-i+1 to numR[N-i+1] Rs of level N-i and X*numR[N-i+1] Bs of level N-i+1 
    numR[N-i]   += numR[N-i+1];
    numB[N-i+1] += X*numR[N-i+1];
    // change Bs of level N-i+1 to numB[N-i+1] Rs of level N-i and Y*numB[N-i+1] Bs of level N-i+1
    numR[N-i]   += numB[N-i+1];
    numB[N-i]   += Y*numB[N-i+1];
  } 
  cout << numB[1] << endl;
  return 0;
}