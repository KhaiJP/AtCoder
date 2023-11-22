#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define PI (double)3.14159265359

double ansewr = 0;
int R[1010], N, r2;

int main(){
  cin >> N;
  rep(i, 0, N) cin >> R[i];
  sort(R, R+N, greater<int>());
  rep(i, 0, N) r2 += (1 - 2*(i&1)) * R[i] * R[i];
  cout << fixed << setprecision(15) << (double)r2 * PI << endl;
  return 0;
}