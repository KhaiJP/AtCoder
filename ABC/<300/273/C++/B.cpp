#include<iostream>
using namespace std;
typedef int64_t ll;

ll pw10(int n);
int main(){
  ll  X; cin >> X;
  int K; cin >> K;
  for(int i=0; i<K; ++i){
    X = X/pw10(i);
    bool isC = X%10 >= 5;
    
    X = (X/10) * pw10(i+1);
    if(isC) X += pw10(i+1);
  }
  cout << X << endl;
  return 0;
}

ll pw10(int n){
  ll ans = 1;
  for(int j=1; j<=n; ++j) ans *= (ll)10;
  return ans;
}