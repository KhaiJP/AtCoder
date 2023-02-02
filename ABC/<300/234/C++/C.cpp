#include<iostream>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int bit[64];

int main(){
  ll K; cin >> K;
  
  int ord;
  rep(i, 0, 64){
    bit[i] = K%2;
    K /= 2;
    if(K <= 0){ ord = i+1; break;} 
  }

  rep(i,1, ord+1) cout << (bit[ord-i] ? 2 : 0);
  return 0;
}