#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int N;
bool isprime[55560];

void EratosthenesSieve(){
  rep(i, 2, 55556) isprime[i] = true;
  rep(i, 2, 55556)if(isprime[i]){
    for(int j = 2; j*i <= 55555; ++j) isprime[j*i] = false;
  }
  return ;
}

int main(){
  cin >> N;
  EratosthenesSieve();
  rep(i, 2, 55555+1)if(isprime[i] && i%5 == 1){
    cout << i << ' ';
    --N;
    if(N == 0){
      cout << endl;
      return 0;
    }
  }
}