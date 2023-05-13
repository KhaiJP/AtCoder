#include<iostream>
#include<algorithm>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
int X[200010], B[200010];

int main(){
  int N; cin >> N;
  rep(i, 0, N){
    cin >> X[i];
    B[i] = X[i];
  }sort(B, B + N);

  rep(i, 0, N){
    if(X[i] > B[(N - 1) / 2]) cout << B[(N - 1) / 2] << '\n';
    else cout << B[(N - 1) / 2 + 1] << '\n';
  }cout << endl;
  return 0;
}