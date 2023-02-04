#include<iostream>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  int N, M; cin >> N >> M;
  
  dsu uf(N);
  int answer = 0;
  rep(i,0,M){
    int A, B; cin >> A >> B;
    --A, --B;
    // if A and B are already connected via some nodes, edge AB yileds cyclic path
    // -> by eliminating edge AB, the graph gets close to SUdG 
    if(uf.same(A, B)) ++answer;
    else uf.merge(A,B);
  }

  cout << answer << endl;
  return 0;
}