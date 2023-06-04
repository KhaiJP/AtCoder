#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int a[110];

int main(){
  int N; cin >> N;
  int tot = 0;
  rep(i, 0, N){
    cin >> a[i];
    tot += a[i];
  }
  
  if(tot % N != 0){
    cout << -1 << endl;
    return 0;
  }
  if(tot == 0){
    cout << 0 << endl;
    return 0;
  }
  
  int avg = tot / N;
  int ans = 0, partial = 0, k = 0;
  rep(i, 0, N){
    partial += a[i];
    ++k;
    if(partial == avg * k){
      ans += k - 1;
      k = 0;
      partial = 0;
    }
  }
  
  cout << ans << endl;
  return 0;
}