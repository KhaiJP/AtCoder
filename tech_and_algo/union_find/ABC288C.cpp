#include<iostream>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  int N, M; cin >> N >> M;
  dsu uf(N);

  int num_edges = 0;
  rep(i, 0, M){
    int A, B; cin >> A >> B; --A, --B;
    if(!uf.same(A, B)){
      ++num_edges;
      uf.merge(A, B);
    }
  }

  cout << M - num_edges << endl;
  return 0;
}