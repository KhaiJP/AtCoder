#include<iostream>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

ll N, Q, pfx[2020][2020];

ll get(ll r, ll c){
  if(r < 0 || c < 0) return 0;
  ll kr = r/N, kc = c/N;
  ll mr = r%N, mc = c%N;
  return kr*kc*pfx[N][N] + kc*pfx[mr][N] + kr*pfx[N][mc] + pfx[mr][mc];
}

int main(){
  cin >> N >> Q;
  rep(i, 0, N)rep(j, 0, N){
    char c; cin >> c;
    pfx[i][j] = c == 'B';
  }
  // 2d prefix sum
  rep(i, 0, N)  rep(j, 0, N) pfx[i][j+1] += pfx[i][j];
  rep(j, 0, N+1)rep(i, 0, N) pfx[i+1][j] += pfx[i][j];
  
  while(Q--){
    ll A, B, C, D; cin >> A >> B >> C >> D;
    cout << get(C, D) - get(C, B-1) - get(A-1, D) + get(A-1, B-1) << endl;
  }

  return 0;
}