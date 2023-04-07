#include<iostream>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

ll S[200010], T[200010];

int main(){
  int N; cin >> N;
  rep(i, 0, N) cin >> S[i];
  rep(i, 0, N) cin >> T[i];

  rep(i, 0, 2*N+1) T[(i+N)%N] = min(T[(i+N)%N], T[(i-1 +N)%N] + S[(i-1+N)%N]);
  
  rep(i, 0, N) cout << T[i] << '\n';
  cout << endl;
  return 0;
}