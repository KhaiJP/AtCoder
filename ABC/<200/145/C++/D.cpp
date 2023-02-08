#include<iostream>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)
#define MOVES_MAX 1000010
ll fact[MOVES_MAX], fact_inv[MOVES_MAX], inv[MOVES_MAX];

const ll MOD = 1000000000+7;
void setComb(ll ul);
ll calComb(ll n, ll k);

int main(){
  ll X, Y; cin >> X >> Y;

  // parity check
  if( (X+Y) % 3 != 0 ){
    cout << 0 << endl;
    return 0;
  }

  // move : number of moves that the knight done
  ll moves = (X+Y)/3;
  if( moves <= X && X <= 2*moves && moves <= Y && Y <= 2*moves ){
    ll moves_X = 2*moves - X;
    // answer = combination(moves+1, dX)
    setComb(moves+1);
    cout << calComb(moves, moves_X) << endl;
  }else cout << 0 << endl;

  return 0;
}

/*-----------------------------------------------------------------------*/
void setComb(ll ul){
  fact[0] = 1, fact[1] = 1;
  fact_inv[0] = 1, fact_inv[1] = 1;
  inv[1] = 1;
  for(ll i = 2; i <= ul; ++i){
    fact[i] = fact[i-1] * i % MOD;
    inv[i]  = MOD - inv[MOD % i] * (MOD/i) % MOD;
    fact_inv[i] = fact_inv[i-1] * inv[i] % MOD;
  }
}
ll calComb(ll n, ll k){
  return fact[n] * ( fact_inv[k] * fact_inv[n-k] % MOD) % MOD;
}