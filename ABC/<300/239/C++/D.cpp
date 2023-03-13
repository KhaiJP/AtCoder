#include<iostream>
using namespace std;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

bool isPrime(int n){
  if(n == 2) return true;
  if(n == 1 || n%2 == 0) return false;
  for(int i = 3; i*i <= n; i += 2){
    if(n%i == 0) return false;
  }
  return true;
}


int main(){
  int A, B, C, D; cin >> A >> B >> C >> D;

  bool takahashi_wins = false;
  // E takahashi in [A, B], A aoki in [C, D], takahashi + aoki is not prime -> Takahashi wins
  rep(takahashi, A, B+1){
    bool no_pair_is_prime = true;

    rep(aoki, C, D+1){
      no_pair_is_prime = no_pair_is_prime && !isPrime(aoki + takahashi);
    }

    if( no_pair_is_prime ){
      takahashi_wins = true;
      break;
    }

  }

  cout << (takahashi_wins ? "Takahashi" : "Aoki") << endl;
  return 0; 
}
