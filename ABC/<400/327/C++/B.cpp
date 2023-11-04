#include<iostream>
using namespace std;
using ll = int64_t;

int main(){
  ll B; cin >> B;
  if(B == 1){
    cout << 1 << endl;
    return 0;
  }

  for(ll i = 2; i <= 18; ++i){
    if(B%i != 0) continue;
    ll cnt = 0, C = B;
    while(C%i == 0){
      C /= i;
      ++cnt;
    }
    if(cnt == i && C == 1){
      cout << i << endl;
      return 0;
    }
  }
  
  cout << -1 << endl;
  return 0;
}