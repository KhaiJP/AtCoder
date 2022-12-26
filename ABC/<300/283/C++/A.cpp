#include<iostream>
#define rep(i, s, t) for(int i=(s); i<(t); ++i)
using namespace std;

int main(){
  int A, B; cin >> A >> B;
  int ans = A;
  rep(i,0,B-1) ans *= A;
  cout << ans << endl;
  return 0;
}