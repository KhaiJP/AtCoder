#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int a[110];

int main(){
  int N, Q; cin >> N >> Q;
  while(Q--){
    int L, R, T; cin >> L >> R >> T;
    rep(i, L, R+1) a[i] = T;
  }

  rep(i, 1, N+1) cout << a[i] << endl;
  return 0;
}