#include<iostream>
#include<numeric>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

// P[p] : number of times that prime p appears for different Ai
// A = (A1, A2) = (2, 4) -> P[2] = 2.
// ∀i P[i] <= 1  <-->  A is pairwise coprime
int P[1000010];

void give_pf(int n){
  if(n%2 == 0){
    ++P[2];
    while(n%2 == 0)n /= 2;
  }

  for(int i = 3; i * i <=n; i += 2){
    if(n % i == 0){
      ++P[i];
      while(n % i == 0) n /= i;
    }
  }

  if(n != 1) ++P[n];
}

int main(){
  int N; cin >> N;

  int g = 0;
  rep(i, 0, N){
    int A; cin >> A;
    g = gcd(g, A);
    give_pf(A);
  }

  bool are_all_unique = P[2] <= 1;
  for(int i = 3; i < 1000000; i += 2) are_all_unique = are_all_unique && P[i] <= 1;

  if(are_all_unique) cout << "pairwise coprime" << endl;
  else if(g == 1) cout << "setwise coprime" << endl;
  else cout << "not coprime" << endl;

  return 0;
}