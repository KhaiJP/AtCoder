#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int N, Q, pfx[300010];
string S;

int main(){
  cin >> N >> Q >> S;
  rep(i, 0, N-1){
    pfx[i+1] = pfx[i] + (S[i] == S[i+1]);
  }

  while(Q--){
    int l, r; cin >> l >> r;
    cout << pfx[r-1] - pfx[l-1] << endl;
  }
  return 0;
}