#include<iostream>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  int N, M; cin >> N >> M;
  
  dsu uf(N);
  rep(i, 0, M){
    int A, B; cin >> A >> B;
    --A, --B;
    uf.merge(A, B);
  }
  cout << uf.groups().size() - 1 << endl;
  return 0;
}