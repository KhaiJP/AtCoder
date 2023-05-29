#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int Tri[1000010];
int const MOD = 10007;

int main(){
  int n; cin >> n;
  Tri[2] = 1;
  rep(i, 0, n) Tri[i+3] = (Tri[i+2] + Tri[i+1] + Tri[i]) % MOD;
  cout << Tri[n-1] << endl;
  return 0;
}