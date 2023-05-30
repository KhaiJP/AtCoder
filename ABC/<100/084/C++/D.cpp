#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

bool isSimilar[100010];
bool isprime[100010];
int pfx[100010];

bool isPrime(int n){
  if(n == 2) return true;
  if(n == 0 || n == 1 || n%2 == 0) return false;

  for(int i = 3; i*i <= n; i += 2)if(n%i == 0) return false;
  return true;
}

int main(){
  isprime[2] = true;
  for(int i = 3; i <= 100000; i += 2) isprime[i] = isPrime(i);
  for(int i = 3; i <= 100000; i += 2)if(isprime[i]) isSimilar[i] = isprime[(i+1) / 2];

  rep(i, 1, 100001) pfx[i] = pfx[i-1] + isSimilar[i];

  int Q; cin >> Q;

  while(Q--){
    int l, r; cin >> l >> r;
    cout << pfx[r] - pfx[l-1] << endl;
  }
  return 0;
}