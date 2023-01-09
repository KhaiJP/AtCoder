#include<iostream>
#include<vector>
using namespace std;
typedef int64_t ll;

int main(){
  ll N; cin >> N;
  vector<ll> L(N+1,0);
  L[0] = 2, L[1] = 1;
  for(int i = 2; i <= N; ++i) L[i] = L[i-1] + L[i-2];
  cout << L[N] << endl;
  return 0;
}