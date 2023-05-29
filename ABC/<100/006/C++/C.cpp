#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  int N, M; cin >> N >> M;
  int y = (M - 2*N) % 2;
  int z = (M - 2*N - y) / 2;
  int x = N - y - z;
  if(x >= 0 && y >= 0 && z >= 0) cout << x << ' ' << y << ' ' << z << endl;
  else cout << -1 << ' ' << -1 << ' ' << -1 << endl;
  return 0;
}