#include<iostream>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int X[2010], Y[2010];
int main(){
  int N, D; cin >> N >> D;
  rep(i, 0, N) cin >> X[i] >> Y[i];
  dsu uf(N);

  rep(i, 0, N-1)rep(j, i+1, N){
    int dx = X[i] - X[j], dy = Y[i] - Y[j];
    if(dx*dx + dy*dy <= D*D) uf.merge(i, j);
  }

  rep(i, 0, N) cout << (uf.same(i, 0) ? "Yes" : "No") << endl;

  return 0;
}