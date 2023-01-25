#include<iostream>
using namespace std;
typedef int64_t ll;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)
#define ll0 (ll)0
ll MAP[101][101], X[101], Y[101], Z[101], N, mZ, H;

int main(){
  cin >> N;
  rep(i,0,N){
    cin >> X[i] >> Y[i] >> Z[i];
    MAP[X[i]][Y[i]] = (Z[i]>0 ? Z[i] : -1);
    mZ = max(mZ, Z[i]);
  }

  rep(cx, 0, 101)rep(cy, 0, 101){
    if( MAP[cx][cy] != 0 && MAP[cx][cy] != mZ ) continue;

    // set H
    ll H = 0;
    rep(i,0,N){
      if(Z[i]==0)continue; // if Z[i] = 0, H cannot be specified
      H = Z[i] + abs(X[i]-cx) + abs(Y[i]-cy);
      break;
    }

    // check if (cx, cy, H) is correct
    bool flag = true;
    rep(i, 0, N){
      ll h = max(H - abs(X[i]-cx) - abs(Y[i]-cy), ll0);
      flag = flag && (Z[i] == h);
      if(!flag)break;
    }

    if(flag){
      cout << cx << ' ' <<  cy << ' ' << H << endl;
      return 0;
    }  
  }
}
