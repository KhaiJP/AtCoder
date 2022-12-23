#include<iostream>
#include<cmath>
using namespace std;

int main(){
  int64_t X, Y; cin >> X >> Y;
  int ans = 0;
  while(X <= Y){
    X = X << 1;
    ans += 1;
  }
  cout << ans << endl;
  return 0;
}