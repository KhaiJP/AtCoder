#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

double v[55];

int main(){
  int N; cin >> N;
  rep(i,0,N) cin >> v[i];
  sort(v, v+N);
  double answer = (v[0]+v[1])/2.0;
  rep(i,2,N) answer = (answer+ v[i])/2.0;
  cout << fixed << setprecision(8) << answer << endl;
  return 0;
}