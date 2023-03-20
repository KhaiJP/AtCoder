#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int A[110][110];

int main(){
  int h, w; cin >> h >> w;
  rep(i, 0, h)rep(j, 0, w){
    int a; cin >> a; --a;
    A[i][j] = a;
  }

  rep(i, 0, h){
    rep(j, 0, w) cout << ( A[i][j] == -1 ? '.' : (char)('A' + A[i][j]) );
    cout << '\n';
  }

  cout << endl;
  return 0;
}