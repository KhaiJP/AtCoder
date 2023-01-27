#include<iostream>
using namespace std;
typedef int64_t ll;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

const ll ul = 1000000;
bool isPrime(ll N);
bool primes[ul+2];
// num_primes[i] = #({p| p in Prime & p <= i}); number of primes no greater than i
ll num_primes[ul+2];


int main(){
  ll N; cin >> N;

  // Sieve of Eratosthenes
  primes[2] = true;
  for(ll p = 3; p <= ul; p += 2) primes[p] = isPrime(p);
  // prefix sum
  rep(i,1,ul+1) num_primes[i] = num_primes[i-1] + (primes[i] ? 1 : 0);

  ll answer = 0;
  ll q = 3;
  while(2 * q*q*q <= N){
    if(!primes[q]){ q += 2; continue;}
    ll mp = min(N/(q*q*q), q-1);
    answer += num_primes[mp];

    q += 2;
  }
  cout << answer << endl;
  return 0;
}

bool isPrime(ll N){
  if(N == 1) return false;
  if(N == 2) return true;
  if(N%2 == 0) return false;
  ll div = 3;
  while(div * div <= N){
    if (N % div == 0) return false;
    div += 2;
  }
  return true;
}