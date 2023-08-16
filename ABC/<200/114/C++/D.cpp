#include<iostream>
#include<vector>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

// pows[i] ; the power of prime i appeared in N!
// n_74 ; number of primes whose power is >= 74
// n_24 ; 24, n_14 ; 14, n_4; 4, n_2 ; 2
int N, pows[110], n_74, n_24, n_14, n_4, n_2;

void set_pows(int n){
  rep(i, 2, n+1)while(n%i == 0){
    ++pows[i];
    n /= i;
  }
  return ;
}

int main(){
  cin >> N;
  rep(i, 1, N+1) set_pows(i);
  
  rep(i, 2, N+1){
    if(pows[i] >= 74)      ++n_74;
    else if(pows[i] >= 24) ++n_24;
    else if(pows[i] >= 14) ++n_14; 
    else if(pows[i] >= 4)  ++n_4;
    else if(pows[i] >= 2)  ++n_2;
  }

  // eg 2^74 has 75 divisors
  int a = n_74;
  // those who are >= 74 are also >= 24
  n_24 += n_74;
  // eg 2^24 * 3^2 has 75 divisors
  int b = n_24 * ((n_24-1) + n_14 + n_4+ n_2);
  // those who are >= 24 are also >= 14 
  n_14 += n_24;
  // eg 2^14 * 3^4 has 75 divisors
  int c = n_14 * ((n_14-1) + n_4);
  // those who are >= 14 are also >= 5
  n_4+= n_14;
  // eg 2^4 * 3^4 * 5^2 has 75 divisors
  int d = (n_4 * (n_4 - 1) / 2) * ((n_4 - 2) + n_2);

  cout << a + b + c + d << endl;
  return 0;
}