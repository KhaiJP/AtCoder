#include<iostream>
using namespace std;
using ll = int64_t;

ll solve(ll H){
  if(H == 1) return 1;
  return 2 * solve(H/2) + 1;
}

int main(){
  ll H; cin >> H;
  cout << solve(H) << endl;
  return 0;
}