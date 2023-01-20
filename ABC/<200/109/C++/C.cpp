#include<iostream>
#include<vector>
#include<numeric>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  int N, X; cin >> N >> X;
  vector<int> x(N); rep(i,0,N) cin >> x[i];
  int answer = abs(x[0]-X);
  rep(i,1,N) answer = gcd(answer, abs(x[i]-X));
  cout << answer << endl;
  return 0;
}