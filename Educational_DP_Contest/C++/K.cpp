#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int N, K, a[110];
bool I_win[100010];

int main(){
  cin >> N >> K;
  rep(i, 0, N) cin >> a[i];

  rep(k, 0, K+1)rep(i, 0, N){
    if(k + a[i] > K) break;
    I_win[k+a[i]] = I_win[k+a[i]] || !I_win[k];
  }

  cout << (I_win[K] ? "First" : "Second") << endl;
  return 0;
}