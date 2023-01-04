#include <iostream>
#include <vector>
#include <map>
#define rep(i, s, t) for (int i = (s); i < (t); ++i)
using namespace std;

int main(){
  int N; cin >> N;
  vector<int> P(N+1, 0); rep(i,2,N+1) cin >> P[i];
  int ans = 0;
  int jun = N;
  while(jun != 1){
    jun = P[jun];
    ans += 1;
  }
  cout << ans << endl;
  return 0;
}