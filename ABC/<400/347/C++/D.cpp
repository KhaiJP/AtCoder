#include<iostream>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)
#define rrep(i, s, t) for(ll i = (s); i >= (t); --i)

// let c = popcount(C). Since popcount(A) + popcount(B) >= popcount(A^B),
// popcount(X) + popcount(Y) = a + b >= popcount(X^Y) = popcount(C) = c,
// which implies a + b < c -> answer = -1.
// let a + b == c. then apprently X and Y can be made by exclusively share 1s in C.
// namely if a=2 and b=3 and C = 0b11111, (X, Y) = (0b11000, 0b00111) is one of the answers.
// if a + b > c, led d = a - b, a_ + b_ = c, (a_, b_) = (a-e, b-e), and e > 0.
// Since (a-d) - (b-d) = a - b = d, following simultaneous Eqs hold;
// (1) a_ + b_ = c (2) a_ - b_ = d.
// hence (a_, b_) = ( (c+d)/2, (c-d)/2 ). -> if (c+d)%2 == 1 (<-> (c-d)%2 ==1 ) the answer = -1.
// X_ and Y_ where popcount(X_) = a_ and popcount(Y_) = b_ and popcount(X_^Y_) = c can be made by the procedure above.
// let z = a - a_ = b - b_ and Z with popcount(Z) = z and Z^C = 0. then (X, Y) = (X_+Z, Y_+Z)

ll L=1;
ll a, b, c, d, C;

ll popcount(ll x, ll m){
  ll res = 0;
  rep(i, 0, 61){
    ll s = ( x & (L << i) ) > 0;
    res += s == m;
  }
  return res;
}

ll extract_Ts(ll E, ll n, int T, int m){
  // extract n times Ts from E from (m==0) LSB, (m==1) MSB.
  // if E = 0b11111, n = 2, T = 1, m = 1 -> return 0b11000
  // if E = 0b10011, n = 1, T = 0, m = 0 -> return 0b00100
  ll res = 0;
  if(m == 0){
    rep(i, 0, 61)if(n > 0){
      ll t = (E >> i) & L;
      if(t == (ll)T){
        res += L << i;
        --n;
      }
    }
  }
  if(m == 1){
    rrep(i, 60, 0)if(n > 0){
      ll t = (E >> i) & L;
      if(t == (ll)T){
        res += L << i;
        --n;
      }
    }
  }

  return res;
}

bool are_OK(ll X, ll Y){
  ll x = popcount(X, L), y = popcount(Y, L);
  ll Z = X ^ Y;
  return x == a && y == b && Z == C;
}

int main(){
  cin >> a >> b >> C;
  c = popcount(C, L);
  d = a - b;
  if(a + b < c || (c+d)%2 == 1){
    cout << -1 << endl;
    return 0;
  }

  ll a_ = (c + d) / 2,  b_ = (c - d) / 2;
  ll X_ = extract_Ts(C, a_, 1, 0), Y_ = extract_Ts(C, b_, 1, 1);
  ll z = a - a_;
  ll Z = extract_Ts(C, z, 0, 0);
  ll X = X_ + Z, Y = Y_ + Z;

  if(are_OK(X, Y)){
    cout << X << ' ' << Y << endl;
  }else{
    cout << -1 << endl; 
  }

  return 0;
}
