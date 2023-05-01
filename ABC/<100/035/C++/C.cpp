#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int F[200010];

int main(){
  int N, Q; cin >> N >> Q;

  rep(i, 0, Q){
    int l, r; cin >> l >> r;
    ++F[l], --F[r+1];
  }

  rep(i, 1, N+1){
    F[i] += F[i-1];
    cout << (F[i] & 1);
  }

  cout << endl;
  return 0;
}